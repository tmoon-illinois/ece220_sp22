#include <stdio.h>
#define SIZE 5
// Helper functions
void print_1D(int array[], int n);
void swap(int *a, int *b);

void BubbleSort(int array[], int n);
void insertSort(int array[], int n);

int partition(int array[], int low, int high);
void quickSort(int array[], int low, int high);

int main(){
    int array[SIZE] =  {5, 1, 4, 2, 8};
    print_1D(array, SIZE);
//    BubbleSort(array, SIZE);
//    insertSort(array, SIZE);

    quickSort(array, 0, SIZE-1);
    print_1D(array, SIZE);
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
    int i;
    int is_swap = 0; // if swap, then 1, else 0.
    do{
        is_swap = 0;
        for(i=0;i<n-1;i++){
            if(array[i] > array[i+1]){//need to swap
                swap( &array[i]  , &array[i+1]  );
                is_swap = 1;
                //swap( array + i  , array +i+1  );
            }
        }
    }while( is_swap == 1 );
}
void insertSort(int array[], int n){

    int sorted, unsorted, unsortedItem;
    for(unsorted = 1; unsorted < n; unsorted++){
        unsortedItem = array[unsorted];
        sorted = unsorted - 1;
        while( unsortedItem < array[sorted] && sorted >=0 ){
            array[sorted+1] = array[sorted];
            sorted--;
        }// finish doing right-shift for red item
        array[sorted+1] = unsortedItem;
    }

}
// partition: do partition and reture the pivot index
int partition(int array[], int low, int high)
{
    int pivot = array[high]; //set the last element as pivot
    int i = low - 1; // index of smaller element
    int j;
    for(j=low;j<=high-1;j++)
    {
        if(array[j] < pivot)
        {
            i++;
            swap( &array[i], &array[j]);
        }
    }
    swap(&array[i+1],&array[high]);
    return i+1;
}
void quickSort(int array[], int low, int high)
{
    //base case
    if(low >= high)
        return;

    //recursive case
    int pivot_idx = partition(array, low, high);
    quickSort(array, low, pivot_idx-1);
    quickSort(array, pivot_idx+1, high);
}




