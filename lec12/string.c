

#include <stdio.h>
#include <string.h>
void string_copy(char des[], char src[]);
int main(){

    char src[10] = "ABC";
    char des[10];

    //des = src; //des is the name array, not variable

    //des = "ABC";
    printf("%s\n", src);
    printf("%s\n", des);
    strcpy(des, src);// from string.h
    //string_copy(des, src);
    printf("%s\n", des);
    scanf("%s", des);
    printf("%s\n", des);
}

// "ABC" => 'A', 'B', 'C', '\n'
void string_copy(char des[], char src[]){

    int i = 0 ;
    while(src[i] != '\0'){
        des[i] = src[i];
        i++;
    }
    des[i] = '\0';
}
