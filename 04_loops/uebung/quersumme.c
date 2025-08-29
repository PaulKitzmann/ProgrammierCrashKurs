#define _CRT_RAND_S

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){


    /*
        Quersumme einer Zahl berechnen
    */


    /*
        Quersumme einer Hex-Zahl berechnen
        Bsp.: 
            num = 0x1234ABCD
            qs  = 0x1 + 0x2 + 0x3 + 0x4 + 0xA + 0xB + 0xC + 0xD = 0x38
    */
    int hex = 0x1234ABCD;
    printf("%x", 1 + 2 + 3 + 4 + 10 + 11 + 12 + 13); // Hexadezimale Zahl ausgeben

    return 0;
}