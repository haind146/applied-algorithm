/*
 * Cho đồ thị vô hướng G(V, E)
 * tìm đồ thị con đầy đủ có số đỉnh lớn nhất
 */

#include <stdio.h>
#include <stack>
#include <set>
#define MAX 10000
using namespace std;

int N, M;
set<int> Adj[MAX];
bool m[MAX];
int best;
int X[MAX], X_best[MAX];
void inputFile(const char* filename) {
    FILE * f=fopen(filename, "r");
    fscanf(f, "%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        int u,v;
        fscanf(f, "%d %d", &u, &v);
        Adj[u].insert(v);
        Adj[v].insert(u);
    }
    fclose(f);
}

void printData() {
    for (int v = 1; v <= N; v++)
    {
        printf("%d: ", v);
        for (set<int>::iterator it = Adj[v].begin(); it != Adj[v].end(); it++) 
        {
            printf("%d ", *it);
        }
        printf("\n");
        
    }
}


bool check(int v, int k) {
    for (int i = 1; i <= k-2; i++)
    {
        if(Adj[X[i]].find(v) == Adj[X[i]].end()) {
            return false;
        }
    }
    return true;
}

void TRY(int k) {
    for (set<int>::iterator it =  Adj[X[k-1]].begin(); it != Adj[X[k-1]].end(); it++)
    {
        int v = *it;
        if(check(v,k)) {
            X[k] = v;
            if(k>best) {
                best = k;
                for(int i=1; i<=k; i++) X_best[i] = X[i];
                printf("Best = %d\n", best);
                if (k<N) {
                    TRY(k+1);
                }
            }
        }
    }
    
}

void solve() {
    best = 1;
    for (int v = 1; v <= N; v++)
    {
        X[1] = v;
        TRY(2);
    }
    printf("maxclique: ");
    for(int i =1; i<=best; i++) printf("%d ", X_best[i]); printf("\n");
}

int main() {
    inputFile("MaxClique.inp");
    solve();
}