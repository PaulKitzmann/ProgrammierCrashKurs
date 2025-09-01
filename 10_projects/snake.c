#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h> 
#include <time.h>

#define WITDH 30
#define HEIGHT 10

enum Direction {
    LEFT = 0,
    DOWN,
    RIGHT,
    UP
};

void clearScreen() {
    // Cursor nach oben links + alles löschen
    printf("\033[H\033[J");
}

void hideCursor() {
    printf("\033[?25l");
}

void showCursor() {
    printf("\033[?25h");
}

void printField(int * snakePos, int snakeLength, int applePos){
    clearScreen();
    for (int i = 0; i<HEIGHT; i++){
        for(int j = 0; j< WITDH; j++){
            int printed = 0;
            if(snakePos[snakeLength - 1] == i*WITDH + j){
                printed = 1;
                printf("#");
            }else
            for(int k = 0; k < snakeLength - 1; k++){
                if(snakePos[k] == i*WITDH + j){
                    printed = 1;
                    printf("o");
                    break;
                }                
            }
            if(applePos == i*WITDH + j){
                printf("@");
                printed = 1;
            };
            if(!printed) printf("-");
        }
        printf("\n");
    }
    fflush(stdout);
}

enum Direction getMove(enum Direction move){
    char c = 0;
    if (kbhit()) {
        c = getch();
    }

    switch (c) {
    case 'w': if (move != DOWN)  return UP;    break;
    case 'a': if (move != RIGHT) return LEFT;  break;
    case 's': if (move != UP)    return DOWN;  break;
    case 'd': if (move != LEFT)  return RIGHT; break;
    default: break;
    }
    return move;
}

void makeMove(int * snakePos, int * snakeLength, int * applePos, enum Direction move){
    int newPos = 0;
    int headPos = snakePos[*snakeLength - 1];
    int heady = headPos / WITDH;
    int headx = headPos % WITDH;

    switch (move)
    {
        case LEFT:
            newPos = heady * WITDH + (headx - 1 + WITDH) % WITDH;
            break;
        case DOWN:
            newPos = ((heady + 1) % HEIGHT) * WITDH + headx;
            break;
        case RIGHT:
            newPos = heady * WITDH + (headx + 1) % WITDH;
            break;
        case UP:
            newPos = ((heady - 1 + HEIGHT) % HEIGHT) * WITDH + headx;
            break;
        default:
            // Optional: handle invalid move
            break;
    }


    if(newPos == *applePos){
        *applePos = rand() % ((HEIGHT - 1) * (WITDH - 1));
        snakePos[*snakeLength] = newPos;
        *snakeLength += 1;
    }
    else{
        for(int i = 0; i<*snakeLength - 1; i++){
            snakePos[i] = snakePos[i+1];
        }
        snakePos[*snakeLength - 1] = newPos;
    }
}

int checkState(int * snakePos, int snakeLength){
    for(int i = 0; i < snakeLength - 1; i++){
        if(snakePos[snakeLength - 1] == snakePos[i])
            return 0;
    }
    return 1;
}

int main (){
    int * snakePos = malloc(WITDH * HEIGHT * sizeof(int));
    int snakeLength = 3;
    int applePos;
    srand(time(NULL));
    //Init
    snakePos[0] = WITDH * 2 + 3;
    snakePos[1] = WITDH * 2 + 4;
    snakePos[2] = WITDH * 2 + 5;
    applePos = WITDH * 2 + 10;
    
    int running = 1;
    enum Direction move = RIGHT;
    while(running){
        printField(snakePos, snakeLength, applePos);
        printf("Score: %d\n", snakeLength);
        move = getMove(move);
        makeMove(snakePos, &snakeLength, &applePos, move);
        running = checkState(snakePos, snakeLength);
        Sleep(150);
    }

    free(snakePos);
    return 0;
}