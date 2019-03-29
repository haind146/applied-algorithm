#include <stdio.h>
#include <queue>

using namespace std;
#define MAX 997

struct State
{
    int x;
    int y;
    State* parent;
};
int n;
int a,b,c;
bool m[MAX][MAX];
queue<State*> Q;

State* initState() {
    State* s = new State;
    s->x = 0;
    s->y = 0;
    return s;
}

bool genStateFill1(State* s) {
    if(m[a%MAX][s->y%MAX]) return false;
    State* news = new State;
    news->x = a; news->y = s->y;news->parent=s;
    m[news->x%MAX][news->y%MAX] = true;
    Q.push(news);
    return news->x==c || news->y==c;
}

bool genStateFill2(State* s) {
    if(m[s->x%MAX][b%MAX]) return false;
    State* news = new State;
    news->x = s->x; news->y = b;news->parent=s;
    m[news->x%MAX][news->y%MAX] = true;
    Q.push(news);
    return news->x==c || news->y==c;
}

bool genStateEmpty2(State* s) {
    if(m[s->x%MAX][0]) return false;
    State* news = new State;
    news->x = s->x; news->y = 0;news->parent=s;
    m[news->x%MAX][news->y%MAX] = true;
    Q.push(news);
    return news->x==c || news->y==c;
}

bool genStateEmpty1(State* s) {
    if(m[0][s->y%MAX]) return false;
    State* news = new State;
    news->x = 0; news->y = s->y;news->parent=s;
    m[news->x%MAX][news->y%MAX] = true;
    Q.push(news);
    return news->x==c || news->y==c;
}

bool genState1to2(State* s) {
    int x_new, y_new;
    if(s->x + s->y > b) {
        y_new = b;
        x_new = s->x - (b-s->y);
    } else {
        y_new = s->x + s->y;
        x_new = 0;
    }
    if(m[x_new%MAX][y_new%MAX]) return false;
    State* news = new State;
    news->x = x_new; news->y = y_new;news->parent=s;
    m[news->x%MAX][news->y%MAX] = true;
    Q.push(news);
    return news->x==c || news->y==c;
}

bool genState2to1(State* s) {
    int x_new, y_new;
    if(s->x + s->y > a) {
        x_new = a;
        y_new = s->y - (a-s->x);
    } else {
        x_new = s->x + s->y;
        y_new = 0;
    }
    if(m[x_new%MAX][y_new%MAX]) return false;
    State* news = new State;
    news->x = x_new; news->y = y_new;news->parent=s;
    m[news->x%MAX][news->y%MAX] = true;
    Q.push(news);
    return news->x==c || news->y==c;
}

int gcd(int n,int m)
{
    if(m<=n && n%m == 0)
        return m;
    if(n < m)
        return gcd(m,n);
    else
        return gcd(m,n%m);
}

void printSolution() {
    if(Q.empty()) {
        printf("-1\n");
    } else {
        int count = 0;
        State * result = Q.back();
        while (result->parent) {
//            printf("%d %d\n", result->x, result->y);
            result=result->parent;
            count++;
        }
        printf("%d\n", count);
    }
}

void solution() {
    while (!Q.empty()) {
        Q.pop();
    }
    State* s0 = initState();
    Q.push(s0);
    while(!Q.empty()) {
        if(genStateFill1(Q.front())) break;
        if(genStateFill2(Q.front())) break;
        if (genStateEmpty1(Q.front())) break;
        if (genStateEmpty2(Q.front())) break;
        if (genState1to2(Q.front())) break;
        if (genState2to1(Q.front())) break;
        Q.pop();
    }
    printSolution();

}

int main() {
//    scanf("%d", &n);
//    for (int i=0;i<n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if(c % gcd(a,b) == 0){
            solution();
        } else {
            printf("-1\n");
//            continue;
        }
//    }
    return 1;

}
