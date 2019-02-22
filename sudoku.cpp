/**
 * 
 * 
 */
#include <stdio.h>

#define MAX 100

// mảng đánh dấu các số đã xuất hiện trên hàng
bool mr[9][10];
// mảng đánh dấu các số đã xuất hiện trên cột
bool mc[9][10];
// mảng đánh dấu các số đã xuất hiện trên các ô vuông con
bool m[3][3][10];

int X[9][9];

bool found = false;
bool check(int v, int row, int col) {
    return !mr[row][v] && !mc[col][v] && !m[row/3][col/3][v];
}

void solution() {
    found = true;
    for(int i=0; i<9; i++){
        for(int j = 0; j<9; j++){
            printf("%d ", X[i][j]);
        }
        printf("\n");
    }

}

void TRY(int row, int col) {
    if(found) return;
    int v = 1;
    for(v=1; v<=9; v++) {
        if(check(v, row, col)) {
            X[row][col] = v;
            mr[row][v] = true;
            mc[col][v] = true;
            m[row/3][col/3][v] = true;
            if(row == 8 && col ==8) {
                solution();
            }
        } else {
            if (col==8) {
                TRY(row +1, col);
            } else  {
                TRY(row, col+1);
            }
        }
        mr[row][v] = false;
        mc[col][v] = false;
        m[row/3][col/3][v] = false;
        
    }
}

void input() {
    for (int i=0; i<9;i++){
        for(int j = 0; j<9; j++){
            scanf("%d", &X[i][j]);
        }
    }
}


int main() {
    input();
    TRY(0,0);
}