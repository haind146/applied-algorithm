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
int N, S, sum, count;
bool result[MAX];

void solution() {
    if(sum == S) {
        count++;
    }

}

void input() {
    scanf("%d", &N);
    scanf("%d", &S);
    for(int i=1; i<=N; i++) {
        scanf("%d", &A[i]);
    }
}


void TRY(int k) {
    for(int v = 0; v <= 1; v++) {
        if(sum + v*A[k] <= S){
            sum += v*A[k];
            if(v==1) {
                result[k] = true;
            }
            if(k==N) {
                solution();
            } else {
                TRY(k+1);
            }
            sum -= v*A[k];
            if(result[k]) result[k] = false;
        }
    }
}
void init() {
    for(int i = 1; i<=N; i++) {
        result[i] = false;
    }
    sum = 0;
}

int main() {
    input();
    init();
    TRY(1);
    printf("%d", count);
}