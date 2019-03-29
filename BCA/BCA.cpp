/**
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
        }
    }
}

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
}