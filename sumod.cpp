#include <stdio.h>

#define MAX 100000


int n;
unsigned long a[MAX], m = 1000000007;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lu", &a[i]);
    }
}

int main() {
    input();
    unsigned long result = 0;
    for (int i = 0; i < n ; ++i) {
        result += a[i] % m;
        result = result % m;
    }
    printf("%lu", result);
}