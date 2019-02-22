/**
 * đầu vào: số phần tử của tập hợp N, số S
 * đầu ra: số tập con của A mà tổng các phần tử = S
 * ví dụ:
 * input:
 * 4 7
 * 1 2 3 4
 * output:
 * 2
 */


#include<stdio.h>

#define MAX 100

int A[MAX];
int N, S, sum;
int result[MAX];
int index;

void TRY() {
    for(int v = 0; v < N; v++) {
        if(sum + A[v] <= S) {
            sum = sum + A[v];
            result[index] = A[v];
            index++;
            if(sum == S) {
                solution();
            } else
            {
                TRY();
            }
            sum = sum - A[v];
            index--;
            
        }
    }
}