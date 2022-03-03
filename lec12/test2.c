#include <stdio.h>

//
//
// x
// input[0]
// input[1]
// input[2]
#define SIZE 3
int main(){
    char input[SIZE];
    int var1 = 0, var2=0;
    char des[SIZE];

    scanf("%s", input);
    printf("%s\n", input);
    printf("%d, %d\n", var1, var2);
    /*
//    fgets(input, SIZE, stdin);
    int rc  =  sscanf(input, "%d%d%s", &var1, &var2, des);
    printf("%s\n", input);
    printf("var1: %d\n", var1);
    printf("vars2: %d\n", var2);
    printf("des: %s\n", des);
    printf("rc: %d\n", rc);
*/
}

