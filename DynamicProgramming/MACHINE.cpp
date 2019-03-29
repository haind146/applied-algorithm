//
// Created by haind on 28/03/2019.
//

#include <stdio.h>

#define MAX 1000000

int A[MAX][2];
int n;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &A[i][0], &A[i][1]);
    }
}

int solve() {
    int maxProduct = 0;
    for (int i = 0; i < n-1 ; ++i) {
        for (int j = i+1; j < n ; ++j) {
            int sum = 0;
            if(A[i][1] < A[j][0] || A[i][0] > A[j][1]) {
                sum = A[i][1] - A[i][0] + A[j][1]-A[j][0];
            }
            if (sum > maxProduct) {
                maxProduct = sum;
            }
        }
    }
    return maxProduct;

}

int main() {
    input();
    printf("%d", solve());
}

/*
5
8 12
 6 11
 3 9
 2 5
 1 4
 */