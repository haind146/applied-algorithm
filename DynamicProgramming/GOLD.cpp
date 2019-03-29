//
// Created by haind on 28/03/2019.
//
#include <stdio.h>
#define MAX 100000
int m;
int n, L1, L2;
int A[MAX];
int B[MAX];


int solve() {
    int maxGlobal = A[0];
    for (int i = 0; i < n ; ++i) {
        if(i-L1<0) {
            B[i] = A[i];
        } else {
            int max = 0;
            for (int j = i-L1; i-j <= L2 && j>=0 ; --j) {
                if (max<B[j]) {
                    max = B[j];
                }
            }
            B[i] = max + A[i];
        }
        if (B[i] > maxGlobal) {
            maxGlobal=B[i];
        }
    }
    return maxGlobal;
}

int main() {
//    scanf("%d", &m);
//    for (int i = 0; i < m ; ++i) {
        scanf("%d %d %d", &n, &L1, &L2);
        for (int j = 0; j < n ; ++j) {
            scanf("%d", &A[j]);
        }
        printf("%d\n", solve());
//    }

}