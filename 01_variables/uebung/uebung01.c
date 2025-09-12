#include <stdio.h>
#include <math.h>

int main(void){
    /*
        Diese Übung dient dazu, sich mit den Datentypen in C vertraut zu machen.
        Wenn du die richtige Ausgabe erhältst, kannst du diesen Abschnitt mit "//" markieren.

        Hilfestellung:

        ------------------------------------------------------------------------------------------------
        |       Data Type        Size           Min Value           Max Value    Format Specifier       |
        |   (signed) char      8 Bits                -128                 127                  %c       |
        |   unsigned char      8 Bits                   0                 255                  %c       |
        |  (signed) short     16 Bits              -32768               32767          %hi or %hd       |
        |  unsigned short     16 Bits                   0               65535                 %hu       |
        |    (signed) int     32 Bits         -2147483648          2147483647            %i or %d       |
        |    unsigned int     32 Bits                   0          4294967295                  %u       |
        |                                                                                               |
        |           float     32 Bits           1.175e-38           3.403e+38       e.g. %f or %F       |
        |          double     64 Bits          2.225e-308          1.798e+308     e.g. %lf or %lF       |
        -------------------------------------------------------------------------------------------------

    */

    // Gib folgende Variablen in der Konsole aus
    int num1 = 98734957;

    printf("%d\n", num1);


    unsigned short num2 = 2025;
    printf("%d\n", num2);


    char num3 = 'A'; //Als buchstabe und als Zahl
    printf("%c, %d\n", num3, num3);
    

    float num4 = 1.5;
    printf("%f\n", num4);

    float num5 = sqrt(2);
    double num6 = sqrt(2);
    //Gib num5 & num6 mit einem "normalem" printf-Statement aus
    printf("%f\n%lf\n", num5, num6);


    // Nun gib num5 & num6 mit 15 Nachkommastellen an
    // Wie viele Nachkommastellen stimmen jeweils?
    printf("%.15f\n%.15lf\n", num5, num6);


    
    short num7 = 0b110110110; //Was ist das?
    printf("%d\n", num7);

    

    int num8 = 0xfade;
    printf("%d, %x\n", num8, num8);

    return 0;
}