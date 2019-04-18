//
// Created by haind on 28/03/2019.
//

#include <stdio.h>

#define MAX 1000000

int A[MAX][2];
int n;

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &A[i][0], &A[i][1]);
    }
}

void swap(int i, int j) {
    int tmp0 = A[i][0];
    int tmp1 = A[i][1];
    A[i][0] = A[j][0];
    A[i][1] = A[j][1];
    A[j][0] = tmp0;
    A[j][1] = tmp1;
}

int partition(int L, int R, int indexPivot) {
    int pivot = A[indexPivot][0];
    swap(indexPivot, R);
    int storeIndex = L;
    for(int i = L; i<=R-1; i++) {
        if(A[i][0]<pivot) {
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
/*
 * return minimal index of value that greater than the given number
 */
int bSearch(int value) {
    int l=1, r=n;
    int mid = l + (r-l)/2;
    while(mid != r && mid !=l) {
        if(A[mid][0] > value) {
            r = mid;
        } else if (A[mid][0] < value) {
            l = mid;
        } else {
            return mid+1;
        }
        mid = l + (r-l)/2;
    }
    if (A[mid+1][0] <= value) {
        return mid+2;
    }
    return mid+1;
}

int solve() {
    quickSort(1,n);
    int maxLeft = A[1][0]-A[1][1];
    int maxLeftIndex = A[1][1];
    int maxRight = 0;
    int maxRightIndex = 0;
    for (int j = bSearch(maxLeftIndex); j <= n ; ++j) {
        if (A[j][1]-A[j][0] > maxRight) {
            maxRight = A[j][1]-A[j][0];
            maxRightIndex = A[j][0];
        }
    }
    int maxProduct = maxLeft + maxRight;
    for (int i = 2; i <= n ; ++i) {
        if (A[i][1] - A[i][0] > maxLeft && A[i][1] < maxRightIndex) {
            maxLeft = A[i][1] - A[i][0];
            maxLeftIndex = A[i][1];
            maxProduct = maxLeft + maxRight;
            continue;
        }
        if (A[i][1] - A[i][0] > maxLeft && A[i][1] >= maxRightIndex) {
            maxLeftIndex = A[i][1];
            maxRight = 0;
            for (int j = bSearch(maxLeftIndex); j <= n ; ++j) {
                if (A[j][1]-A[j][0] > maxRight) {
                    maxRight = A[j][1]-A[j][0];
                    maxRightIndex = A[j][0];
                }
            }
            if (maxRight ==0) {
                return maxProduct;
            }
        }
        if (maxLeft+maxRight > maxProduct) {
            maxProduct = maxLeft + maxRight;
        }
    }
    return maxProduct;

}



int main() {
    input();
    printf("%d", solve());
}

/*
5
8 12
 6 11
 2 5
 1 4
 3 9
 */