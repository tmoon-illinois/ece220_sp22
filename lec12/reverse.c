#include <stdio.h>
#define SIZE 5

void array_reverse(int array[], int n);
//void array_reverse(int *array, int n);
//void array_reverse(int array[SIZE], int n);
void print_array(int array[], int n);
int main(){
    int arr[SIZE] = {1,2,3,4,5};

    print_array(arr, SIZE);

    array_reverse(arr, SIZE);
    print_array(arr, SIZE);


    int a, b, result;
    // output: 3*2/3 = 2
    result = 3;
    a = 2;
    b = 3;
    result = result * a / b; // <=> result *= a/b
    //result = a / b * result; // <=> result *= a/b
    //result *= a/b; // result *= 2/3 = 0
    printf("%d\n", result);

}
// index: 0 1 2 3 4
// input: 1 2 3 4 5
// output: 5 4 3 2 1
// input: 1 2 3 4 
// output: 4 3 2 1 
// input: 1 2 3
// output: 3 2 1
// number of loop = floor(n/2)
void array_reverse(int array[], int n){
    int i;
    int temp;
    for(i = 0; i < n/2 ; i++){
        temp = array[i];
        array[i] = array[n-1-i];
        array[n-1-i] = temp;
    }
    /*
    int *a, *b;
    a = array;
    b = &array[0] -1;
    while()*/
}
void print_array(int array[], int n){
    int i;
    for(i=0; i<n; i++){
        //printf("%d ", array[i]);
        printf("%d ", *(array+i) );
    }
    printf("\n\n");
}

