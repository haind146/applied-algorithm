//
// Created by haind on 21/03/2019.
//

#include <stdio.h>

#define MAX 100000000
int n;
int a[MAX];


void input() {
    scanf("%d", &n );
    for (int i = 0; i <n ; ++i) {
        scanf("%d", &a[i]);
    }
}
int  solve() {
    int S;
    S = a[0];
    int ans = S;
    for (int i = 1; i < n; ++i) {
        if (S > 0) {
            S = S + a[i];
        } else {
            S = a[i];
        }
        if(ans<S) {
            ans = S;
        }
    }
    return S;
}

int main() {
    input();
    printf("%d", solve());
}