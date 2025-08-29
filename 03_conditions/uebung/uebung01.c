#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


int timeInMilliseconds(void) {
    struct timeval tv;

    gettimeofday(&tv,NULL);
    return ((tv.tv_sec)*1000)+(tv.tv_usec/1000);
}

int main() {
    unsigned int currentTime = timeInMilliseconds();
    srand(currentTime);

    /*
        Aufgabe 1:
        Der Variable num wird eine zufällige Zahl zwischen 0 und 10 zugewiesen.
        Gib mit einem printf-Statement aus, ob sie gerade ist.
    */
    

    int num = rand() % 100;
    printf("%d", num);


    return 0;
}