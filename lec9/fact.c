#include <stdio.h>

int Fact(int);


int main(){
    int number;
    int answer;
    printf("Enter a numbner: ");
    scanf("%d", &number);

    answer = Fact(number);
    printf("factorial of %d is %d\n", number, answer);
    return 0;
}

int Fact(int n){
    //n = n + 1;
    int i, result = 1;
    for(i=1;i<=n;i++){
        result = result *i;
    }
    return result;
}


