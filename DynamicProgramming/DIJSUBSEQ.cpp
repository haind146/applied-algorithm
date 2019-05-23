/*
 * Cho dãy a1, a2, .. an
 * Tìm 2 dãy con không giao nhau sao cho tổng các phần tử của 2 dãy là lớn nhất
 * Ví dụ:
 * Stdin:
 * 5
 * 2 3 -4 1 -5
 * stdout:
 * 6
 */
#include <stdio.h>

#define MAX 1000000

int N;
int A[MAX];

void input() {
    scanf("%d", &N);
    for(int i = 1; i<=N; i++) {
        scanf("%d", &A[i]);
    }
}

void solve() {
    int sum_left=0, sum_right = 0;
    sum_left = A[1]

}