/*
 * Đồ thị vô hướng G(V,E), w(u,v) là trọng số cạnh (u,v)
 * Cây con T của G là đồ thị vô hướng, liên thông và không có chu trình T(V',E')
 * Trong đó V' là tập con của V, E' là tập con của E
 * Cây khung T(V', E') của G trong đó V' trùng V, E' trùng E
 * Cây khung nhỏ nhất (MST) là cây khung có tổng trọng số trên cạnh nhỏ nhất 
 * Thuật toán: 
 * KRUSKAL: tham lam
 *  Mỗi bước lặp chọn ra cạnh nhỏ nhất để kết nối đỉnh sao cho không tạo ra chu trình
 * 
 * 
 *  Sử dụng Disjoin Set: cấu trúc các tập không giao nhau
 *      Cung cấp 2 hàm:
 *          + find(u): trả về đỉnh đại diện cho tập chứa đỉnh u
 *          + union(u,v): Ghép 2 tập chứa u và v thành 1 tập
 */ 

#include <iostream>
#include <set>
#define MAX 100001

using namespace std;

int N, M;
int u[MAX];
int v[MAX];
int c[MAX];
int ranks[MAX];
int p[MAX];

void link(int x, int y) {
    if (ranks[x] > ranks[y] ) p[y] = x;
    else
    {
        p[x] = y;
        if(ranks[x] == ranks[y]) ranks[y] = ranks[y] +1;
    
    }
    
}

void makeSet(int x) {
    p[x] = x;
    ranks[x] = 0;

}
int findSet(int x) {
    if(x!= p[x])
    p[x] = findSet(p[x]);
    return p[x];
}

void input() {
    cin >> N >> M;
    for(int i =0; i<M; i++) {
        int iu, iv, iw;
        cin >> iu >> iv >> iw;
        u[i] = iu;
        v[i] = iv;
        c[i] = iw;
    }
}

void swap(int &a, int &b) {
    int tmp = a; a=b; b=tmp;
}

void swapEdge(int i, int j) {
    swap(c[i], c[j]);
    swap(u[i], u[j]);
    swap(v[i], v[j]);
}

int partition(int L, int R, int index) {
    int pivot = c[index];
    swapEdge(index, R);
    int storeIndex = L;
    for(int i = L; i<=R-1 ; i++) {
        if(c[i]<pivot) {
            swapEdge(storeIndex, i);
            storeIndex++;
        }
    }
    swapEdge(storeIndex, R);
    return storeIndex;
}

void quickSort(int L, int R) {
    if(L<R) {
        int index = (R+L)/2;
        index = partition(L,R, index);
        if(L<index) quickSort(L, index-1);
        if(index<R) quickSort(index+1, R);
    }
}

void quickSort() {
    quickSort(0, M-1);
}

void solve() {
    for(int x = 1; x<= N; x++) {
        makeSet(x);
    }
    quickSort();
    int rs = 0;
    int count = 0;
    for(int i = 0; i<M; i++) {
        int ru = findSet(u[i]);
        int rv = findSet(v[i]);
        if(ru != rv) {
            link(ru, rv);
            rs += c[i];
            count++;
            if(count == N-1) break;
        }
    }
    cout << rs;
}

int main() {
    input();
    solve();
}

/* input sample
8 15
1 3 1
1 6 8
1 7 1
1 8 1
2 4 6
2 5 2
2 6 5
3 5 1
3 6 1
4 6 7
4 7 1
4 8 3
5 6 1
6 7 2
7 8 2

*/