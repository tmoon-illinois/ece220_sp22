

#include <stdio.h>
int y = 0;
int main(){
    
    int x= 0;
    // print 0 to 9
    while( y < 10     ){
        printf("%d", y);
        y++;
    }

    printf("\n");
    y = 0;
    do{
        printf("%d", y);
        y++;
    }while( y < 10 );


    printf("\n");
    for( y =0  ; y<10  ; y++ ){
        printf("%d", y);
    }


/*
    if(x == 1)
        printf("1\n");
    else if(x == 1)
        printf("0\n");
    else
        printf("?\n");


    if(x == 1)
        printf("1\n");
    if(x == 1)
        printf("0\n");
        */
}

