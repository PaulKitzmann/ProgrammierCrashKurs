#include <stdio.h>

int main(){
    signed char c = 0;
    signed char last = 0;
    while(c >= 0){
        last = c;
        c++;
    }

    printf("c is negative?? Value: %d\n", c);
    printf("last value of c: %d\n", last);

    
    return 0;
}