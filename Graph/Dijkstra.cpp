/*
 * Tìm đường đi ngắn nhất từ 1 đỉnh đến tất cả các đỉnh còn lại trên đồ thị trọng số
 * Đồ thị trọng số không âm
 * Thuật toán:
 * d[v]: là độ dài cận trên dường đi ngắn nhất từ s -> v
 * p[v]: đỉnh trước đỉnh v trên đường đi cận trên ( được cải thiện trong từng bước lặp)
 * 
 * NonFixed: tập các đỉnh chưa có nhãn (p[v], d[v]) cố định (chưa tìm được đường đi lớn nhất từ s đến nó)
 * Fixed: 
 */

#include <stdio.h>
#include <list>
#define MAX 10000
int N, M;
int s, t;
int G[MAX][MAX];
int d[MAX], p[MAX];
using namespace std;

void input(const char * filename) {
    FILE * f = fopen(filename,"r");
    fscanf(f, "%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        fscanf(f, "%d %d %d", &u, &v, &w);
        G[u][v] = w;
    }
    fscanf(f, "%d %d", &s, &t);
    fclose(f);
}

void dijkstra() {
    list<int> nonFixed;
    list<int> fixed;
    for (int v = 1; v <= N; v++)
    {
        if (v != s)
        {
            if(G[s][v] > 0) {
                d[v] = G[s][v];
                p[v] = s;
            } else
            {
                d[v] = 100000000;
                p[v] = s;
            }
            nonFixed.push_back(v);
            
        } else
        {   
            d[v] = 0;
            p[v] = s;
            fixed.push_back(v);
        }
    }
   

    while (!nonFixed.empty())
    {
        int x;
        int min = 100000;
        for (list<int>::iterator it = nonFixed.begin(); it != nonFixed.end(); it++)
        {
            int v = *it;
            if(d[v] < min) {
                min = d[v];
                x = v;
            }
        }
        nonFixed.remove(x);
        fixed.push_back(x);
        printf("%d\n", x);
        for (list<int>::iterator it = nonFixed.begin(); it != nonFixed.end(); it++)
        {
            int v = *it;
            if(G[x][v] != 0) {
                if(d[v] > d[x] + G[x][v]) {
                    d[v] = d[x] + G[x][v];
                    p[v] = x;
                }
            }
            
        }
        for (int i = 1; i <= N; i++)
        {
            printf("(%d,%d) \t", d[i], p[i]);
        }
        printf("\n");
        
    }
}

void solution() {
    int x = t;
    int sum = 0;
    while (p[x] != s)
    {
        sum += d[x];
        printf("%d", x);
        x = p[x];
    }
    printf("%d", sum);
    
}

int main() {
    input("Dijkstra.inp");
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            printf("%d \t", G[i][j]);
        }
        printf("\n");
    }
    
    dijkstra();
    // solution();
}



