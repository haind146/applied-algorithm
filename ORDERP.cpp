/*
 * Cần sắp xếp N phần tử 1,2,.. N theo thứ tự trong list L 
 * Với L là danh sách các cặp (i,j) 
 * sao cho khi  sắp xếp thì i phải dứng trước j
 * viết chương trình đếm số cách có thể sắp xếp (Q)
 * INPUT:
 * line 1: N
 * line 2: K
 * line k+1: i j
 * .
 * .
 * (1<= k <=K) 
 * OUTPUT:
 * Q
 */


#include <stdio.h>
#include <set>

#define MAX 100000

using namespace std;

set<int> L[MAX];
int N, K;
bool m[MAX];
int result[MAX];
int count;

void input() {
    scanf("%d", &N);
    scanf("%d", &K);
    for (int i = 1; i <= K; i++)
    {
        int u,v;
        scanf("%d %d", &u, &v);
        L[v].insert(u);  
    }
    
}

bool check(int v) {

    if(m[v]) {
       return false; 
    }

    for(set<int>::iterator it = L[v].begin(); it != L[v].end(); it++) {
        int u = *it;
        if(!m[u]) {
            return false;
        }
    }
    return true;
} 

void TRY(int k) {
    for(int v=1; v<=N; v++) {
        if(check(v)) {
            result[k] = v;
            m[v] = true;
            if(k==N) {
                count++;
                for (int i = 1; i <= N; i++)
                {
                    printf("%d ", result[i]);
                }
                printf("\n");
                
            } else
            {
                TRY(k+1);
            }
            m[v] = false;
        }
    }
}

int main() {
    input();
    TRY(1);
    printf("%d", count);
}

