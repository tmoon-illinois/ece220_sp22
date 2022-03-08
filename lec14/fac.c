#include <stdio.h>


int fact_iter(int n);
int fact_rec(int n);
int main(){
    printf("fact_iter(4) = %d\n", fact_iter(4)); 
    printf("fact_rec(4) = %d\n", fact_rec(4)); 
}
int fact_iter(int n){
    int i, result = 1;
    for(i=n;i>0;i--)
        result = result*i;
    return result;
}
int fact_rec(int n){
    if(n == 1)
        return 1;
    else
        return n*fact_rec(n-1);
}

