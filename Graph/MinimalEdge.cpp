/*
 * Tìm đường đi từ s đén t đi qua một số điểm cho trước với số cạnh ít nhất
 * 
 */

#include <stdio.h>
#include <stack>
#include <set>
#define MAX 10000
using namespace std;

int N, M, s, t;
int L;
int B[MAX];
set<int> A[MAX];
bool m[MAX];
int best;
int X[MAX], X_best[MAX];
void inputFile(const char* filename) {
    FILE * f=fopen(filename, "r");
    fscanf(f, "%d %d %d %d", &N, &M, &s, &t);
    for (int i = 0; i < M; ++i) {
        int u,v;
        fscanf(f, "%d %d", &u, &v);
        A[u].insert(v);
        A[v].insert(u);
    }
    fscanf(f, "%d", &L);
    for (int i = 1; i <= N;i++) fscanf(f, "%d", &B[i]);
    fclose(f);
}

void printData() {
    for (int v = 1; v <= N; v++)
    {
        printf("%d: ", v);
        for (set<int>::iterator it = A[v].begin(); it != A[v].end(); it++) 
        {
            printf("%d ", *it);
        }
        printf("\n");
        
    }
}
