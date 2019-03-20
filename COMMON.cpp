#include <stdio.h>
#define MAX 1000000

int a[MAX];
int b[MAX];
int n,m;

void input() {
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
    }
    for(int i=1;i<=m;i++) {
        scanf("%d", &b[i]);
    }
}

void swap(int i, int j) {
    double tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int partition(int L, int R, int indexPivot) {
    double pivot = a[indexPivot];
    swap(indexPivot, R);
    int storeIndex = L;
    for(int i = L; i<=R-1; i++) {
        if(a[i]<pivot) {
            swap(storeIndex, i);
            storeIndex++;
        }
    } 
    swap(storeIndex, R);
    return storeIndex;
}

void quickSort(int L, int R) {
    if(L<R) {
        int index = (L+R)/2;
        index = partition(L, R, index);
        if(index > L+1) quickSort(L, index-1);
        if(index < R-1) quickSort(index+1, R);
    }
}

void printResult() {
    for(int i = 1; i<=n; i++) printf("%d ", a[i]);
    printf("\n");
}

int bSearch(int value) {
    
    int l=1;
    int r=n;
    int mid;
    while(1) {
        mid = (r+l)/2;
        if(a[mid] == value) {
            return mid;
        } 
        if(l==r) return 0;
        if (a[mid] < value)
        {
            l = mid +1;
        } else
        {
            r = mid;
        }
    }
    return 0;
}

int main() {
    input();
    quickSort(1,n);
    int count=0;
    // printf("%d", bSearch(4));
    for(int i=1; i<=m; i++) {
        if(bSearch(b[i]) !=0) count++;
    }
    printf("%d", count);
}