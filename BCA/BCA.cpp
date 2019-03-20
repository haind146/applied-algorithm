/**
<<<<<<< HEAD
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
=======
 * samsung1.pdf
 */
#include <stdio.h>

#define MAX 100

int M, N;
bool conflict[MAX][MAX];
bool assign[MAX][MAX];
bool canTeach[MAX][MAX];

void init();
void input() {
    scanf("%d %d", &M, &N);
    init();
    for(int i = 1; i<=M; i++) {
        int numCourse;
        scanf("%d", &numCourse);
        for(int j =1; j<=numCourse; j++) {
            int courseNo;
            scanf("%d", &courseNo);
            canTeach[i][courseNo] = true;
        }
    }
    int numOfConflict;
    scanf("%d", &numOfConflict);
    for(int k = 0; k<= numOfConflict; k++) {
        int a,b;
        scanf("%d", &a);
        scanf("%d", &b);
        conflict[a][b] = true;
        conflict[b][a] = true;
    }

}
bool check(int v, int k){
    if(canTeach[v][k]) {
        for(int i = 1; i <= N; i++) {
            if(conflict[k][i] && assign[v][i] && k!= i) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }

}

void solution() {
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            if(assign[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    printf("------------\n");}

void TRY(int k) {
    for(int v = 1; v<=M; v++) {
        if(check(v, k)) {
            assign[v][k] = true;
            if(k==N) {
                solution();
            } else {
                TRY(k+1);
            }
            assign[v][k] = false;
>>>>>>> 31da7e3f442e164637d06f7cce6b4cf49d6e1f2f
        }
    }
}

<<<<<<< HEAD
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
=======
void init() {
    for(int i = 0; i <= M; i++) {
        for(int j=0 ; j<=N; j++) {
            assign[i][j] = false;
            canTeach[i][j] = false;
        }
    }
    for(int i = 0; i <= N; i++) {
        for(int j=0 ; j<=N; j++) {
            conflict[i][j] = false;
        }
    }
}

int main() {
    input();
    TRY(1);
>>>>>>> 31da7e3f442e164637d06f7cce6b4cf49d6e1f2f
}