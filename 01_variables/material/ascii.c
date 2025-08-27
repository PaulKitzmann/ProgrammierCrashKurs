#include <stdio.h>


int main(){

    printf("%4c", ' ');
    for(int i = 0; i < 16; i++){
        printf("%4d", i);
    }
    printf("\n");
    for(int num = 32; num < 256; num+=16){
        printf("%4d", num);
        for(int j = num; j < num + 16; j++){
            printf("%4c", j);
        }
        printf("\n");
    }

    return 0;
}