/** 
 * Liệt kê xâu nhị phân độ dài n có đúng M bit bằng 1
 * input: n, M
*/

#include <stdio.h>
#define MAX 100
int x[MAX];
int n,M;
int count;
int T;
void solution() {
    count++;
	printf("%d. ",count);
	for(int i=1;i<=n;i++)
	printf("%d",x[i]);
	printf("\n");
}

bool check(int v, int k) {
    return (T + v <= M) && (n - k + T + v >= M);
}

void TRY(int k) {
    int v;
    for(v=0; v<=1; v++) {
        if(check(v, k)) {
            x[k] = v;
            T = T + v; // cap nhat khi gia tang
            if(k == n ) {
                solution();
            }
            else {
                TRY(k+1);
            }
            T = T - v; //khoi puc khi Backtrack
        }
    }
}

void input() {
    scanf("%d",&n);
    scanf("%d",&M);
}
void solve() {
    count = 0;
    TRY(1);
    T=0;
}
int main() {
    input();
    solve();
}