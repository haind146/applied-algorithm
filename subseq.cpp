//
// Created by haind on 21/03/2019.
//

#include <stdio.h>

#define MAX 100000
int N;
unsigned long M;
unsigned long a[MAX];


void input() {
    scanf("%d %lu", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%lu", &a[i]);
    }
}

int solve() {
//    int count = 0;
//    int i=0, j=0;
//    unsigned long S=0;
//    for(i=0; i<N; i++){
//        if(a[i]<=M) {
//            S+= a[i];
//            if(i==N-1) {
//                if(S<=M) {
//                    for(int k = 0; k<= i-j+1; k++) {
//                        count += k;
//                    }
//                }
//            }
//            if(S>M) {
//                for(int k = 0; k<= i-j; k++) {
//                    count += k;
//                }
//                while(S>M) {
//                    S = S - a[j];
//                    j++;
//                }
//            }
//        } else {
//            j = i+1;
//            S=0;
//        }
//    }
    int count=0;
    unsigned long S = 0;

    for (int i = 0; i < N; ++i) {
        int j=0;
        while(j+i<N) {
            S=0;
            for (int k=j; k<=j+i; k++) {
                S += a[i];
            }
            if(S<=M) {
                count++;
            }
            j++;
        }
    }
    return count;
}
int main() {
    input();
    printf("%d", solve());
}