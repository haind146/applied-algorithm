#include <stdio.h>
#define MAX 1000000

double a[MAX];
int n;

void input() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%lf", &a[i]);
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
    for(int i = 1; i<=n; i++) printf("%0.2lf ", a[i]);
    printf("\n");
}

void heapify(int i, int N) {
    int L = 2*i;
    int R = 2*i+1;
    int max = i;
    if(L<=N && a[L] > a[max]) max = L;
    if(R<=N && a[R] > a[max]) max = R;
    if(max != i) {
        swap(i,max);
        heapify(max, N);
    }
}
void buildHeap() {
    for(int i = n/2; i >= 1; i--) {
        heapify(i,n);
    }
}

void heapSort() {
    buildHeap();
    for(int i=n; i>1; i--) {
        swap(1, i);
        heapify(1, i-1);
    }
}

int main() {
    input();
    quickSort(1,n);
//    heapSort();
    printResult();
}