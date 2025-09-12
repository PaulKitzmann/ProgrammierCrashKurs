#include <stdio.h>
#include <time.h>
#include <stdarg.h>

#define RED_BG "\033[0;41m"
#define BLACK_BG "\033[0;40m"
#define RESET "\033[0m"
#define BLACK_TXT "\033[0;30m"
#define WHITE_TXT "\033[0;37m"
#define GREEN_BG "\033[0;42m"
#define MAGENTA_BG "\033[0;45m"
#define BLUE_BG "\033[0;44m"
#define GRAY_BG "\033[0:46m"
#include <windows.h>

#include <conio.h>
#define clrscr() printf("\e[1;1H\e[2J")

void title()
{
    puts("_________               .__                                                   ._._._.");
    puts("\\_   ___ \\_____    _____|__| ____   ____   ____   ____   ____   ____   ____   | | | |");
    puts("/    \\  \\/\\__  \\  /  ___/  |/    \\ /  _ \\ /  _ \\ /  _ \\ /  _ \\ /  _ \\ /  _ \\  | | | |");
    puts("\\     \\____/ __ \\_\\___ \\|  |   |  (  <_> |  <_> |  <_> |  <_> |  <_> |  <_> )  \\|\\|\\|");
    puts(" \\______  (____  /____  >__|___|  /\\____/ \\____/ \\____/ \\____/ \\____/ \\____/   ______");
    puts("        \\/     \\/     \\/        \\/                                             \\/\\/\\/");
    puts("\n\n");
}

void moveCursor(int dx, int dy)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    COORD pos = csbi.dwCursorPosition;
    pos.X += dx;
    pos.Y += dy;

    SetConsoleCursorPosition(hConsole, pos);
}

void highlightNumber(int number, char color)
{
    if (number < 0 || number > 36)
        return;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    // Koordinaten der Zahl im Konsolenpuffer ermitteln:
    // Deine printf-Schleife gibt die Zahlen in Blöcken aus:
    // | XX |
    // -> wir müssen aus number die "Zeile" und die "Spalte" berechnen

    int rowOffset = 9; // Anzahl Zeilen über dem Spielfeld (Logo, Rahmen)
    int colStart = 6;  // Spaltenoffset (wo die erste Zahl beginnt)
    int colWidth = 6;  // Breite pro Zahl inkl. "| xx "

    COORD pos;
    if (number == 0)
    {
        // Null ist bei dir unter der 12 in einer eigenen Spalte
        pos.X = colStart - 4;
        pos.Y = rowOffset + 1;
    }
    else
    {
        int row = (number - 1) / 12; // 0..2
        int col = (number - 1) % 12; // 0..11
        pos.X = colStart + col * colWidth + 2;
        pos.Y = rowOffset + row;
    }

    WORD oldAttr;
    DWORD read;
    ReadConsoleOutputAttribute(hConsole, &oldAttr, 1, pos, &read);
    // printf("%d: %x\t", number, oldAttr);

    // Neue Attribute: Vordergrund unverändert, Hintergrund = blau
    WORD newAttr = 0xF0;
    if (!color)
    {
        if (number == 0)
        {
            newAttr = (oldAttr & 0x0F) | (BACKGROUND_GREEN);
        }
        else if (number % 2 == 0)
        {
            newAttr = (oldAttr & 0x0F) | (BACKGROUND_BLUE);
        }
        else if (number % 2 == 1)
        {
            newAttr = (oldAttr & 0x0F) | (BACKGROUND_RED);
        }
    }
    // Auf zwei Zeichen (Zahl) anwenden
    DWORD written;
    for (int i = 0; i < 4; i++)
    {
        WriteConsoleOutputAttribute(hConsole, &newAttr, 1, pos, &written);
        pos.X++;
    }
}

void updateInfoRow(int row, int col, const char *fmt, ...)
{
    // Save current cursor position
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    COORD oldPos = csbi.dwCursorPosition;
    oldPos.Y -= 1;

    // Format the string
    char buffer[128];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    // Move cursor to target position
    COORD pos = {.X = (SHORT)col, .Y = (SHORT)row};
    SetConsoleCursorPosition(hConsole, pos);

    // Print new value
    printf("%s", buffer);
    fflush(stdout);

    // Restore cursor to original position
    SetConsoleCursorPosition(hConsole, oldPos);
}

void clearCurrentRow()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Get console info
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    SHORT row = csbi.dwCursorPosition.Y; // last row
    if (row < 0)
        row = 0;

    int width = csbi.dwSize.X; // console width

    // Move to start of last row
    COORD pos = {0, row};
    SetConsoleCursorPosition(hConsole, pos);

    // Overwrite entire row with spaces
    for (int i = 0; i < width; i++)
        printf(" ");
    fflush(stdout);

    // Leave cursor at beginning of cleared row
    SetConsoleCursorPosition(hConsole, pos);
}

void clearLastRow()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Get current console info
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    int width = csbi.dwSize.X;               // console width
    SHORT row = csbi.dwCursorPosition.Y - 1; // last row

    if (row < 0)
        row = 0; // prevent negative row

    // Move to beginning of last row
    COORD pos = {0, row};
    SetConsoleCursorPosition(hConsole, pos);

    // Overwrite entire row with spaces
    for (int i = 0; i < width; i++)
        printf(" ");
    fflush(stdout);

    // Move cursor to beginning of cleared row
    SetConsoleCursorPosition(hConsole, pos);
}

void drawHeader()
{
    puts(RED_BG WHITE_TXT "__________             .__          __    __                 " RESET);
    puts(BLACK_BG WHITE_TXT "\\______   \\ ____  __ __|  |   _____/  |__/  |_  ____   ____  " RESET );
    puts(RED_BG WHITE_TXT " |       _//  _ \\|  |  \\  | _/ __ \\   __\\\   __\\/ __ \\_/ __ \\ " RESET );
    puts(BLACK_BG WHITE_TXT " |    |   (  <_> )  |  /  |_\\\  ___/|  |  |  | \\  ___/\\  ___/ " RESET);
    puts(RED_BG WHITE_TXT " |____|_  /\\____/|____/|____/\\___  >__|  |__|  \\___  >\\___  >" RESET);
    puts(BLACK_BG WHITE_TXT "        \\/                       \\/                \\/     \\/ " RESET);
    printf("\n\n");
}

void drawBoard()
{

    printf(WHITE_TXT "+-----------------------------------------------------------------------------+\n" RESET);

    printf(WHITE_TXT "|     " RESET);
    for (int i = 1; i <= 36; i++)
    {
        if (i % 2 == 0)
            printf(WHITE_TXT "| " BLUE_BG " %2d " RESET, i);
        else
            printf(WHITE_TXT "| " RED_BG " %2d " RESET, i);

        // Zeilenumbruch nach jeder 12 Zahlen für bessere Lesbarkeit
        if (i == 12)
        {
            printf(WHITE_TXT "|\n| " GREEN_BG " %2d " RESET, 0);
        }
        if (i == 24)
        {
            printf(WHITE_TXT "|\n| "
                             "    " RESET);
        }
    }

    printf(WHITE_TXT "|\n+-----------------------------------------------------------------------------+\n" RESET);
    printf("+--------------------+\n");
    printf("| COLOR : %10s |\n", "???");
    printf("| NUMBER: %10s |\n", "???");
    printf("| BET   : %10s |\n", "CHOOSE BET"); // Beispiel für Wetteinsatz
    printf("+--------------------+\n");
}

int editNumber()
{
    printf("SELECT YOUR NUMBER [1 <= n <= 36]: ");
    int number = 0;
    scanf("%d", &number);
    updateInfoRow(16, 0, "| BET   : %10d |", number);
    return number;
}

char *editColor()
{
    printf("SELECT YOUR COLOR [B / R]: ");
    char color = ' ';
    getchar();
    scanf("%c", &color);
    if (color == 'b' || color == 'B')
    {
        updateInfoRow(16, 0, "| BET   : %10s |", "BLUE");
        return "BLUE";
    }
    else if (color == 'r' || color == 'R')
    {
        updateInfoRow(16, 0, "| BET   : %10s |", "RED");
        return "RED";
    }
}

int spin()
{
    // Färbe die nächsten 5 Zeichen ab dem Cursor in der Farbe GRAU
    int randomNumber = rand() % 500;
    for (int n = 0; n <= randomNumber; n++)
    {
        highlightNumber((n - 1) % 37, 0);
        highlightNumber(n % 37, 1);

        int sleepTime;
        if (n > randomNumber - 10)
        {
            // wir sind in den letzten 10 Schritten
            int stepInLast10 = n - (randomNumber - 10); // 1..10
            int minSleep = 10;
            int maxSleep = 200;

            // linear interpolieren
            sleepTime = minSleep + (maxSleep - minSleep) * stepInLast10 / 10;
        }
        else
        {
            // mittlerer Bereich: linear ansteigend
            sleepTime = 5;
        }

        Sleep(sleepTime);
    }
    return randomNumber % 37;
}
void roulette()
{
    clrscr();
    ULONGLONG now_ms = GetTickCount64();
    srand((unsigned int)(now_ms & 0xFFFFFFFF));
    char running = 1;
    drawHeader();
    drawBoard();
    printf("BET ON NUMBER [1] | BET ON COLOR [2] | SPIN [3] | EXIT [0]\n");
    int numberBet = -1;
    char *colorBet = "";
    while (running)
    {
        int eingabe;
        if (scanf("%d", &eingabe) != 1)
        {
            // invalid input, flush stdin
            while (getchar() != '\n')
                ;
            continue;
        }
        clearLastRow();

        switch (eingabe)
        {
        case 1:
        {
            numberBet = editNumber();
            clearCurrentRow();
            break;
        }
        case 2:
        {
            colorBet = editColor();
            clearCurrentRow();
            break;
        }
        case 3:
        {
            int result = spin();
            char *color = "";
            updateInfoRow(15, 0, "| NUMBER: %10d", result);
            if (result == 0)
                color = "GREEN";
            else if (result % 2 == 1)
                color = "RED";
            else if (result % 2 == 0)
                color = "BLUE";
            updateInfoRow(14, 0, "| COLOR : %10s", color);
            moveCursor(0, 2);
            if (result == numberBet || color == colorBet)
            {
                printf("DU HAST GEWONNEN JUHU");
            }
            else
            {
                printf("DU HAST VERLOREN");
            }
            Sleep(2000);
            updateInfoRow(15, 0, "| NUMBER: %10s", "???");
            updateInfoRow(14, 0, "| COLOR : %10s", "???");
            moveCursor(0, 2);

            clearCurrentRow();
            break;
        }
        case 0:
            printf("Exiting...\n");
            Sleep(1000);
            running = 0;
            break;
        default:
            puts("WRONG INPUT IDIOT\n");
        }
    }
    return;
}

int main()
{
    int running = 1;
    while (running != 0)
    {
        clrscr();
        title();
        printf("Wähle dein Spiel aus:\n");
        printf("ROULETTE [1] | EXIT [0]\n");
        int eingabe;
        scanf("%d", &eingabe);

        switch (eingabe)
        {
        case 1:
            roulette();
            break;
        case 0:
            running = 0;
            break;

        default:
            break;
        }
    }
    return 0;
}