#include <stdio.h>
#define N 5
#define M 3
void print_2D(int row, int col, int a[][col]);
void matrix_change(int matrix[][M], int x, int y);
void matrix_tr(int des[][N], int src[][M]);

int main()
{
    int i, j;
    int matrix[N][M];
    printf("Initialize Matrix: \n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            matrix[i][j]= i*M+ j + 1;
        }
    }
    print_2D(N, M, matrix);
    printf("New Matrix: Swap row 0 and 2\n");
    //matrix_change(matrix, 0, 2);
    print_2D(N, M, matrix);

    int matrix_T[M][N];
    matrix_tr(matrix_T, matrix);
    printf("New Matrix: Transpose\n");
    print_2D(M, N, matrix_T);
    
}
// Swap x-th row and y-th row
void matrix_change(int matrix[][M], int x, int y)
{
}
// Transpose src matrix and store in des matrix
void matrix_tr(int des[M][N], int src[N][M])
{

}
void print_2D(int row, int col, int a[][col])
{
    int i, j;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            printf("%-5d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

