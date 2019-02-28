/**
 * Có n công việc 1,2,...,n
 * Và n thợ 1,2,3,...n
 * Chi phí thuê thợ i thực hiện công việc j là C(i,j) -> ma trận nxn
 * Tính phương án thuê thợ thực hiện n việc sao cho:
 * Mỗi công việc được thực hiện bởi đúng 1 thợ
 * Tổng chi phí thuê thợ -> min 
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int n;
int c[MAX][MAX];
int f, f_min;
int x[MAX], x_min[MAX];
int c_min;
int m[MAX];

void input (const char* fn) {
    FILE* f= fopen(fn,"r");
    fscanf(f,"%d",&n);
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            fscanf(f,"%d",&c[i][j]);
            if( i!=j && c[i][j] < c_min) c_min = c[i][j];
        }
    }
    fclose(f);
}


void genData(char* fn, int n) {
    FILE* f= fopen(fn,"w");
    fprintf(f, "%d\n", n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int x = rand()%20 +1;
            fprintf(f, "%d ",x);
        }
        fprintf(f,"\n");

    }
    fclose(f);
}

void updateBest(int k, int v) {
    if(f + c[k][v] < f_min) {
        f_min = f + c[k][v];
        for (int i =1;i <=n; i++)
            x_min[i] = x[i];
        printf("best = %d\n", f_min);
    }
}
 
void TRY(int k) {
    for(int v=1; v<=n; v++) {
        if (!m[v]) {
            x[k] = v;
            m[v] = true;
            f= f + c[k][v];
            if (k==n) updateBest(k,v);
            else
            {
                int g = f + c_min*(n-k+1);
                if(g<f_min)
                    TRY(k+1);
            }
            f= f- c[k][v];
            m[v] = false;  
        }
    }
}

void printSolution() {
    for(int i = 1; i <= n; i++) printf("%d ", x_min[i]);
    printf("\n");
}

main() {
    genData("PHANCONG-10.INP", 20);
    f = 0;
    f_min = 100000000;
    input("PHANCONG-10.INP");
    TRY(1);
    printSolution();
}