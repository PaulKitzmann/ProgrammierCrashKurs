#include <stdio.h>

int main(){

    /*
        Logical Operators:
         a >  b : a größer b
         a >= b : a größer oder gleich b
         a <  b : a kleiner b
         a <= b : a kleiner oder gleich b
         a == b : a gleich b
         a != b : a ungleich b

         a && b : a und b (logisches und)
         a || b : a oder b (logisches oder)
        
        ALLE logischen Operatoren geben
            1, wenn wahr
            0, wenn falsch
        zurück.
    */

    //Beispiele

    int a = 5;
    int b = 10;

    printf("%d > %d = %d\n", a, b, a > b);
    printf("%d < %d = %d\n", a, b, a < b);
    printf("%d != %d = %d\n", a, b, a != b);

    printf("%d && %d = %d\n", a, b, a && b);
    printf("%d || %d = %d\n", a, b, a || b);

    return 0;
}