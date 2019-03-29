//
// Created by haind on 28/03/2019.
//

/*
 * Dãy con chung dài nhất
 * tìm dãy con chung dài nhất của hai dãy:
 * { x1, x2, ..., xn}
 * { y1, y2, ..., yn}
 *
 * S(i,j)  là độ dài dãy con chung dài nhất của dãy X và Y
 *
 * - Bài toán con nhỏ nhất:
 *      Với mọi j - 1..m: S(1,j) =  1 nếu x1 xuâts hiện trong y1,...ỵj
 *                                  0 ngược lại
 *
 */

#include <stdio.h>

#define MAX 1000

int X[MAX];
int Y[MAX];
int x_length, y_length;
int A[MAX][MAX];


int solve() {
    for (int i = 0; i < x_length ; ++i) {
        if (X[i]==Y[0]) {
            A[i][0] = 1;
        } else {
            A[i][0] = 0;
        }

    }
    for (int j = 0; j < y_length ; ++j) {
        if (X[0]==Y[j]) {
            A[0][j] = 1;
        } else {
            A[0][j] = 0;
        }
    }
    for (int k = 1; k < x_length ; ++k) {
        for (int l = 0; l < y_length ; ++l) {
            if (X[k] == Y[l]) {
                A[k][l] = A[k-1][l] > A[k][l-1] ? A[k-1][l] + 1 : A[k][l-1] +1;
            } else {
                A[k][l] = A[k-1][l] > A[k][l-1] ? A[k-1][l] : A[k][l-1];
            }
        }
    }
    return A[x_length-1][y_length-1];
}

void input() {
    scanf("%d", &x_length);
    for (int i = 0; i < x_length ; ++i) {
        scanf("%d", &X[i]);
    }
    scanf("%d", &y_length);
    for (int j = 0; j < y_length ; ++j) {
        scanf("%d", &Y[j]);
    }
}

int main() {
    input();
    int ans = solve();
    printf("%d", ans);
}

/*
 * test
7
3 7 2 5 1 4 9
10
4 3 2 3 6 1 5 4 9 7
 */