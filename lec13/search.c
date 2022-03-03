#include <stdio.h>

int linear_search(int array[], int L, int H, int key);
int binary_search(int array[], int L, int H, int key);
void print_1D(int array[], int n);
int main(){
    int array[5] = {1, 3, 5, 11, 20};
    print_1D(array, 5);

    int key;
    printf("enter a key value: ");
    scanf("%d", &key);

    printf("index of key : %d\n", binary_search(array, 0, 4, key));


    return 0;
}
// n= size of array
void print_1D(int array[], int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ", array[i]);
    printf("\n");
}
int linear_search(int array[], int L, int H, int key){
    return -1; // no key item in array
}
// output index of the matched item
int binary_search(int array[], int L, int H, int key){
    int M;
    while( H >= L ){
        M = (L+H)/2;
        if( array[M] == key)
            return M;
        else if( array[M] < key)
            L = M + 1;
        else // array[M] > key
            H = M - 1;
    }
    return -1;
}
