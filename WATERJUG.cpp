#include <stdio.h>
#include <queue>

using namespace std;
#define MAX 100

struct State
{
    int x;
    int y;
    State* parent;
};

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
    if(m[a][s->y]) return false;
    State* news = new State;
    news->x = a; news->y = s->y;news->parent=s;
    m[news->x][news->y] = true;
    Q.push(news);
    return news->x==c || news->y==c;
} 

bool genStateFill2(State* s) {
    if(m[s->x][b]) return false;
    State* news = new State;
    news->x = s->x; news->y = b;news->parent=s;
    m[news->x][news->y] = true;
    Q.push(news);
    return news->x==c || news->y==c;
} 

bool genStateEmpty2(State* s) {
    if(m[s->x][0]) return false;
    State* news = new State;
    news->x = s->x; news->y = 0;news->parent=s;
    m[news->x][news->y] = true;
    Q.push(news);
    return news->x==c || news->y==c;
} 

bool genStateEmpty1(State* s) {
    if(m[0][s->y]) return false;
    State* news = new State;
    news->x = 0; news->y = s->y;news->parent=s;
    m[news->x][news->y] = true;
    Q.push(news);
    return news->x==c || news->y==c;
}

bool genState1to2(State* s) {
    if(m[0][s->y]) return false;
    State* news = new State;
    news->x = 0; news->y = s->y;news->parent=s;
    m[news->x][news->y] = true;
    Q.push(news);
    return news->x==c || news->y==c;
}

int main() {
    State* s0 = initState();
    Q.push(s0);
    while(!Q.empty()) {
        if(genStateFill1) break;
    }
}
