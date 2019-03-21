#include <stdio.h>
#include <queue>
#define MAX 100
using namespace std;

int N, L1, L2;
int list[MAX];
queue<int> Q;

void input() {
    scanf("%d %d %d", &N, &L1, &L2);
    for (int i = 0; i < N ; ++i) {
        scanf("%d", &list[i]);
        Q.push(list[i]);
    }
}

int main() {
    while (!Q.empty()) {
        Q.
    }

}
