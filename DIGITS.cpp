/**
 * đọc số nguyên đầu vào N
 * in ra số Q cachs gán các số 1,2,.. 9 vào các chữ cái I, C, T, K, H, U, S
 * ICT - K62 + HUST = N
 * in ra số kết quả thay được
 * ví dụ:
 * input:
 * 1234
 * output:
 * 24
 */

#include<stdio.h>
// I:C[0] ... K:C[6]

int C[6];
int N;
int count;
bool xh[10];


void solution() {
    int T = C[0]*100 + C[1]*10 + C[2] - C[3]*100 - 62 + C[4]*1000 + C[5]*100 + C[6]*10 + C[2];
    if(T==N){
        count++;
    }
    
}

void TRY(int x) {

    for(int v = 1; v <= 9; v++) {
        if(!xh[v]) {
            C[x] = v;
            xh[v] = true;
            if(x==6) {
                solution();
            } else
            {
                TRY(x+1);
            }
            xh[v] = false;
        }
    }
}
void init() {
    for(int i = 1; i<9; i++) xh[i] = false;
}

main() {
    init();
    scanf("%d", &N);
    TRY(0);
    printf("%d", count);
}