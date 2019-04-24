//
// Created by haind on 11/04/2019.
//

/*
 * Một công ty phân phối hàng hóa cần phân bổ M cửa hàng cho N đơn vị quản lý, các đơn vị quản lý đánh số 1,..N
 * Đơn vị quản lý i có ai nhân viên (i = 1..N). số của hàng được phân về 1 đơn vị quản lý phải > 0 và chia hết cho số nhân viên của đơn vị
 * Yêu cầu: từ giá trị M,N và dãy a1...aN. tính xem có tất cả bao nhiêu cách phân bổ
 */

#include <stdio.h>
#define MAX 1000
#define OVERFLOW 1000000007
int N, M, A[MAX];
int S[101][501];

void input() {
    scanf("%d %d", &N, &M );
    for (int i = 1; i <= N ; ++i) {
        scanf("%d", &A[i]);
    }
}

int add(int a, int b) {
    a = a%OVERFLOW;
    b  = b%OVERFLOW;
    int z = OVERFLOW - a;
    int c;
    if(z>b) c = a+b;
    else c= b-z;
    return c;
}

int main() {
    input();
    int Q;

    for (Q = 1; Q <= M ; Q++) {
        if (Q%A[1] == 0)  {
            S[1][Q] = 1;
        } else {
            S[1][Q] = 0;
        }
    }

    for (int i = 2; i <= N ; ++i) {
        for (Q = 1; Q <=M ; ++Q) {
            S[i][Q] = 0;
            int sum = 0;
            for (int j = 1; j < i ; ++j) {
                sum += A[j];
            }
            for (int v = 1; v <= (Q-sum)/A[i] ; ++v) {
                if (Q-A[i]*v > 1) {
                    S[i][Q] = add(S[i][Q], S[i-1][Q-A[i]*v]);
                }
            }
        }

    }
    printf("%d",S[N][M]);
    printf("\n");
//    for (int k = 1; k <=N ; ++k) {
//        for (int l = 1; l <= M ; ++l) {
//            printf("%d",S[k][l]);
//
//        }
//        printf("\n");
//    }
}