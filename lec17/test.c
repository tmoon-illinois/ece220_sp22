#include <stdio.h>

enum weekday {SUN = 7, MON = 1, TUE};

int main(){
    enum weekday today;

    printf("%d, %d, %d\n", SUN, MON, TUE);

    char c[100];
    scanf("%s", c);
    scanf("%s", &(c[0]));
}
