#include <stdio.h>

int k, n;

void input() {
    scanf("%d %d", &k, &n);
}
int kToN(int k, int n) {
}

int main() {
    input();
    int cKn = 1;
    cKn = kToN(k,n);
    for(int i = 1; i <= n-k; i++) {
        cKn = cKn/i;
    }
    printf("%d", cKn);
    return 0;
}



