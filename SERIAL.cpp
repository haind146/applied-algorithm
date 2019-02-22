/**
 * phân tích một số N thành tổng các số nguyên có thể  có và in ra các số theo thứ tự từ điển
 * N = a0 +  a1 + ... +an
 * ví dụ:
 * input: 4
 * output: 
 * 1 1 1 1
 * 1 1 2
 * 1 3
 * 2 2
 * 4
 */
#include<stdio.h>

#define MAX 100

int A[MAX];
int N;
int sum =0;
int index;

void solution(){
    bool isSolution = true;

    for(int i = 1 ; i < index; i++) {
        if(A[i-1] > A[i]) isSolution = false;
    }
    if(isSolution){
        for(int J = 0; J<index; J++) {
            printf("%d ", A[J]);
        }
        printf("\n");
    }
    
}

void TRY() {
    if(index == N) return;
    for(int v = 1; v<=N; v++) {
        if(sum + v <= N) {
            sum = sum + v;
            A[index] = v;
            index++;
            if(sum == N) solution();
            else TRY();
            sum = sum - v;
            index--;
        }
    }
}  

main() {
    scanf("%d", &N);
    index = 0;
    TRY();
}