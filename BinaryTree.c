//
// Created by nguye on 4/14/2019.
//


#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

struct _Node {
    int label;
    struct Node * leftChild;
    struct Node * rightChild;
};


typedef struct _Node Node;
int result[MAX];
int n;
void TRY(int k) {
    for (int v = 0; v <= 1 ; ++v) {
        if(k<n) {
            result[k] = v;
            TRY(k+1);
        } else {
            result[k]=v;
            for (int i=1; i<=n; i++) {
                printf("%d", result[i]);
            }
            printf("\n");
        }
    }
}

int main() {
    n=10;
    TRY(1);
}