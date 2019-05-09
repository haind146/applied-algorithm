#include <stdio.h>
#include <stack>
#include <set>
#define MAX 10000
using namespace std;

int N, M;
set<int> Adj[MAX];

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

void solve() {
    stack<int> S;
    stack<int> CE;
    S.push(2);
    while (!S.empty())
    {
        int x = S.top();
        if(Adj[x].size() > 0) {

        }
    }
    
}

int main() {
    inputFile("./Euler.inp");
    printData();
}