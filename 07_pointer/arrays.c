#include <stdio.h>


int main(){
    long long array[10] = {0};

    for(int i = 0; i < 10; i++){
        printf("%d\n", &array[i]);
    }
    return 0;
}