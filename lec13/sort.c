#include <stdio.h>
#define SIZE 8
// Helper functions
void print_1D(int array[], int n){
void swap(int *a, int *b);

void BubbleSort(int array[], int n);
void insertSort(int array[], int n);

int main(){
    return 0;
}
void print_1D(int array[], int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ", array[i]);
    printf("\n");
}
void swap(int *a, int *b){
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}
void BubbleSort(int array[], int n){
}
void insertSort(int array[], int n){
}
