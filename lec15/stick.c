#include <stdio.h>
/* max number of sticks */
#define N 10
#define M 3

//const int set[M] = {3,7,10};
const int set[M] = {10,7,3};
// solution[N]: stores the solution
// idx: index for the solution matrix
// total: remaining length 
//
// total = 3
// my first try = solution [0] = 3
// recursive call solve(solution, 1, 0)
//
int solve(int solution[N], int idx,  int total){
    int j;
    // base case
    if( total == 0 && idx <= N  ){
        return 1;
    }
    // recursive
    else{
        for(j=0;j<M;j++){
            if( total - set[j] >= 0    ){//safe move
                solution[idx] = set[j]; // make decision
                if( solve(solution, idx+1, total - set[j]) == 1)
                    return 1;
                else
                    solution[idx] = 0;
            }
        }
        return 0;
    }
}

int main(){
    int solution[N] = {0};
    int total, i;

    printf("Enter total length: ");
    scanf("%d", &total);

    if(solve(solution, 0, total)){
        printf("A solution found:\n");
        for(i=0;i<N;i++)
            printf("%d ", solution[i]);
    }
    else
        printf("No solution exists.\n");
}

