#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG printf("TEST\n");

typedef struct {
    int all;
    int bd[9][9];
} board;

int total=0;

int check(board b,int n) {
    int row = n/9;
    int col = n%9;
    int block_col = col/3;
    int block_row = row/3;
    int conflict = 0;
    if(n==81){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                printf("%d ",b.bd[i][j]);
            }
            printf("\n");
        }
        return 1;
    }
    if(b.bd[row][col]!=0){
        return (check(b,n+1));
    }
    for(int try_in=1; try_in<=9; try_in++) {
            conflict = 0;
            for(int i=0; i<9; i++){
                if(((row!=i) && (b.bd[row][i]==try_in)) || ((col!=i) && (b.bd[i][col]==try_in)))
                    conflict = 1;
            }
            if (!conflict) {
                for (int i = 0; i < 3 && !conflict; i++)
                    for (int j = 0; j < 3 && !conflict; j++)
                        if (b.bd[3*block_row+i][3*block_col+j]== try_in)
                            conflict = 1;
                if (!conflict) {
                    b.bd[row][col] = try_in;
                    if (check(b,n+1))
                        return 1;
            }
        }
    }
    b.bd[row][col] = 0;
    return 0;
}

int main() {
    board a;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            scanf("%d",&a.bd[i][j]);
        }
    }
    check(a,0);
    return 0;
}