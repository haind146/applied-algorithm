#include <iostream>
#include <fstream>
#include <set>
#include<stack>
#define MAX 90000

using namespace std;

struct Edge {
    int x;
    int w;
};
int N,M;
int NN;
set<Edge*> A[MAX];
set<int> S; //tap ung cu vien ket nap dan vao cay khung
int d[MAX];
int pred[MAX];
bool found[MAX];
int s,t;
int node[MAX];
int idx[MAX];

void swap(int i, int j) {
    int tmp = d[i]; d[i] = d[j]; d[j] = tmp;
    tmp = node[i]; node[i] = node[j]; node[j] = tmp;
    idx[node[i]] = i; idx[node[j]] = j;
}

void heapify(int i, int n) {
    int L = 2*i;
    int R = 2*i+1;
    int min = i;
    if(L<=n && d[L] < d[i]) min = L;
    if(R<=n && d[R] < d[min]) min = R;
    if(min != i) {
        swap(i,min);
        heapify(min, n);
    }
}

void buildHeap() {
    for(int i = N/2; i>=1; i--) {
        heapify(i,N);
    }
}

void upHeap(int i) {
    int p = i;
    while(p/2 >= 1) {
        if(d[p] <d[p/2]) {
            swap(p,p/2);
            p = p/2;
        } else
        {
            break;
        }
        
    }
}
int selectMin() {
    int sel_v = node[1];
    swap(1, N);
    N = N-1;
    heapify(1,N);
    return sel_v;
}

void init() {
    for (int i = 1;i<=N; i++) {
        node[i] = i;
        idx[i] = i;
    }
    for (int v = 1; v<= N; v++) {
        d[v] = 10000000;
        d[idx[s]] = 0;
        for (set<Edge*>::iterator q = A[s].begin(); q != A[s].end(); q++) {
            Edge* e = *q;
            int v = e->x;
            int w = e->w;
            d[idx[v]] = w;
            pred[v] = s;
        }
        buildHeap();

    }
}

void solve() {
    for(int v =1; v<=N; v++) if(v!=s) 
        found[v] = false;
    found[s] = true;
    init();
    int s = selectMin();
    while(N>0) {
        int v = selectMin();
        found[v] = true;
        for(set<Edge*>::iterator q = A[v].begin(); q!= A[v].end(); q++) {
            Edge* e = *q;
            int u = e->x;
            if(found[u] == false) {
                int w = e->w;
                if(d[idx[u]] >d[idx[v]] + w) {
                    d[idx[u]] = d[idx[v]] + w;
                    pred[u] = v;
                    upHeap(idx[u]);
                }
            }
        }
    }
    cout << "result= " <<d[idx[t]] << endl;
    stack<int> path;
    int x = t;
    while (x != s) {
        path.push(x);
        x= pred[x];
    }

    cout <<s;
    while(!path.empty()) {
        int x = path.top();
        path.pop();
        cout << "-->" << x;
    }
    
}

void input() {
    cin >> N >>M; NN = N;
    for(int i = 0; i<M; i++) {
        int u, v, w;
        cin >> u >>v >>w;
        Edge* e = new Edge;
        e->x = v;
        e->w = w;
        A[u].insert(e);
    }
    cin >> s >> t;
}

int main() {
    input();
    solve();
}