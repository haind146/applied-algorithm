//
// Created by haind on 21/03/2019.
//

#include <stdio.h>

int c[16][16];
int N, M;
int x[16];
bool m[16];
int c_min = 1000000;
int count =0;
int f;

void input() {
    scanf("%d %d",&N, &M);
    for (int i = 1; i <= N ; ++i) {
        for (int j = 1; j <= N ; ++j) {
            scanf("%d", &c[i][j]);
            if(c[i][j] < c_min) {
                c_min = c[i][j];
            }
        }
    }
}

void solution() {
    if(f + c[x[N]][x[1]] <= M){
        count++;
    }
}

void TRY(int k) {
    for(int v=1; v<=N; v++) {
        if (!m[v]) {
            x[k] = v;
            m[v] = true;
            f=f+c[x[k-1]][x[k]];
            if (k==N) solution();
            else
            {
                int g = f + c_min*(N-k+1);
                if(g<=M)
                    TRY(k+1);
            }
            f= f- c[x[k-1]][x[k]];
            m[v] = false;
        }
    }
}

int main() {
    f=0;
    count =0;
    input();
    x[1] = 1;
    m[1] = true;
    TRY(2);
    printf("%d",count);
}

