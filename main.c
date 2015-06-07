#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG printf("TEST\n");

typedef struct {
    int row;
    int column;
    int bd[9][9];
}board;

int total=0;

void check(board b){
    board t;
    
}

int main(){
    board a;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            scanf("%d",&a.bd[i][j]);
        }
    }
    check(a);
    return 0;
}