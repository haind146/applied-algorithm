/** 
 * tìm nghiệm nguyên dương của phương trình a1.x1 + a2.x2 +...+ an.xn = M
 * input:
 * n M
 * a1 a2 ... an
 * output:
 * số nghiệm của phương trình: count
*/

#include <stdio.h>
#define MAX 100
int x[MAX], a[MAX];
int n,M;
int count=0;
int T;
void solution() {
    if(T == M){
        count++;
    }
    
}

bool check(int v, int k) {
    return (T + v*a[k] <=M);
}

void TRY(int k) {
    int v;
    for(v=1; v<=M; v++) {
        if(check(v, k)) {
            x[k] = v;
            T = T + v*a[k]; // cap nhat khi gia tang
            if(k == n) solution();
            else
            {
                TRY(k+1);
            }
            T = T - v*a[k]; //khoi puc khi Backtrack
            
        }
    }
}

void input() {
    scanf("%d %d", &n, &M);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
}
void solve() {
    count = 0;
    TRY(1);
    printf("%d", count);
}
int main() {
    input();
    solve();
}