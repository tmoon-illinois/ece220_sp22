

#include <stdio.h>

#define TIP 0.20

int main(){

    double bill, total;

    printf("Type the bill: ");
    scanf("%lf", &bill);

    total =  TIP*bill + bill;

    printf("Total: %lf\n", total);

    return 0;


}
