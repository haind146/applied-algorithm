/**
 * Bài toán người du lịch TSP
 * Dư liệu vào: ma trận chi phí Cij đi từ thành phố i-> tp j
 * 1 phương án: (x1, x2, ..., xn)
 * hàm mục tiêu f(x) = C(x1,x2) + ... C(xn-1, xn)
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int n;
int m[MAX];
int c[MAX][MAX];
int x[MAX]; //solution
int x_min[MAX];
int f, f_min;
int c_min;

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
            if(i==j) x = 0;
            fprintf(f, "%d ",x);
        }
        fprintf(f,"\n");

    }
    fclose(f);
}

void updateBest() {
    if(f + c[x[n]][x[1]] < f_min) {
        f_min = f + c[x[n]][x[1]];
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
            f=f+c[x[k-1]][x[k]];
            if (k==n) updateBest();
            else
            {
                int g = f + c_min*(n-k+1);
                if(g<f_min)
                    TRY(k+1);
            }
            f= f- c[x[k-1]][x[k]];
            m[v] = false;  
        }
    }
}

void printSolution() {
    for(int i = 1; i <= n; i++) printf("%d", x_min[i]);
    printf("\n");
}

main() {
//    genData("TSP-15", 15);
     f = 0;
     f_min = 100000000;
     x[1] = 1;
     m[1] = true;
     input("TSP.INP");
     TRY(2);
     printSolution();
}