#include <stdio.h>


int rek(unsigned int num){
    if(num == 0)
        return 0;

    return 1 + rek(num - 1);
}


int main(){
    printf("%d\n", rek(10));

    return 0;
}