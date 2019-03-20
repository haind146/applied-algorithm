/**
 * Balance Courses Assignment
 * samsung1.pdf
 */

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int m, n;
int max_load, max_load_min;
bool conflict_courses[MAX][MAX];
bool can_teach[MAX][MAX];
bool teach[MAX][MAX];
bool teach_min[MAX][MAX];
int count_assigned_courses[MAX];

void updateBest() {
    if(max_load < max_load_min) {
        max_load_min = max_load;
        for (int i =1;i <=m; i++)
            for(int j = 1; j<=n; j++)
                teach_min[i][j] = teach[i][j];
        printf("best = %d\n", max_load_min);
    }
}

bool check(int k,int v) {
    
}
 
void TRY(int k) {
    for(int v=1; v<=n; v++) {
        if (check(k, v)) {
            teach[k][v] = true;
            count_assigned_courses[k] += 1;
            if (k==m) updateBest();
            else
            {
                if(v==n)
                    TRY(k+1);
            }
            teach[k][v] = false;
            count_assigned_courses[k] -= 1;
        }
    }
}

void printSolution() {
    for(int i = 1; i <= n; i++) printf("%d", x_min[i]);
    printf("\n");
}

main() {
    genData("TSP-15", 15);
    // f = 0;
    // f_min = 100000000;
    // x[1] = 1;
    // m[1] = true;
    // input("TSP.INP");
    // TRY(2);
    // printSolution();
}