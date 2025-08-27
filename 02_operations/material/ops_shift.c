#include <stdio.h>


void print_binary(unsigned char num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main(void){
    char num = 0b10101010;

    print_binary(num);

    print_binary(num << 1);
    print_binary(num >> 1);

    return 0;    
}