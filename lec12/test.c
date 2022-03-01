


#include <stdio.h>

int main(){
    double word[10] = {1,2,3};
    double *cptr;
    cptr = word;

    printf("%p\n", cptr);
    printf("%p\n", word);
    printf("%p\n", &word[0]);
    
   
    printf("\n\n");
    printf("%p\n", cptr+1);
    printf("%p\n", word+1);
    printf("%p\n", &word[1]);
}


    
