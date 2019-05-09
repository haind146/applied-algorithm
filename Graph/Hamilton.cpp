#include <stdio.h>
#include <stack>
#include <set>
#define MAX 10000
using namespace std;

int N, M;
set<int> Adj[MAX];
bool m[MAX];
int X[MAX];
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

void solution() {
    for (int i = 1; i <= N; i++)
    {
        printf("%d ", X[i]);
    }
    printf("\n");
}

void Try(int k) {
    for (set<int>::iterator it = Adj[X[k-1]].begin(); it != Adj[X[k-1]].end(); it++)
    {   
        int v = *it;
        if(!m[v]) 
        {
            X[k] = v;
            m[v] = true;
            if(k==N) 
            {
                if( Adj[X[N]].find(X[1]) != Adj[X[N]].end()) {
                    solution();
                }
            } else
            {
                Try(k+1);
            }
            m[v] = false;
            
        }
    }
    
}

void solve() {

}

int main() {
    inputFile("./Euler.inp");
    printData();
    X[1] = 1;
    m[1] = true;
    Try(2);
}