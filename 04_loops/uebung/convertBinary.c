#include <stdio.h>

void convertToBinary(unsigned int num, int length){
    //from highest to lowest bit
    for(int i = length - 1; i >= 0; i--){
        int bit = num & (1 << i);
        printf("%d", bit != 0);
    }
    printf("\n");
}

int main(){
    /*
        Gib die binäre Darstellung von num aus
    */

    unsigned int num = 0b1001010110111;
    convertToBinary(num, sizeof(unsigned int) * 8);

    char num2 = -5;
    convertToBinary(num2, sizeof(char) * 8);

    return 0;
}