//
// Created by haind on 28/03/2019.
//

/**
 * Nurse Scheduling Listing
 * samsung-1.pdf
 */

#include <stdio.h>

#define MAX 100

int A[MAX], countPeriod;
int N, K1, K2;
int count = 0;

void solution() {
    count++;

}

bool check(int k, int v) {
    if(k ==1) return true;
    if(v==0) {
        if(countPeriod >= K1 && (N - k>= K1 || k==N)) {
            return true;
        } else
        {
            return false;
        }

    } else if (v==1);
    {
        if (countPeriod + 1 <= K2) {
            return true;
        } else
        {
            return false;
        }
    }


}

void Try(int k) {
    for (int v=0; v<=1; v++) {
        if(check(k,v)) {
            A[k] = v;
            if(v==1) countPeriod++;
            int temp = countPeriod;
            if(v==0) countPeriod = 0;
            if (k==N) {
                solution();
            } else
            {
                Try(k+1);
            }
            if(v==1) countPeriod--;
            if(v==0) countPeriod = temp;
        }
    }
}

int main() {
    count = 0;
    scanf("%d %d %d", &N, &K1, &K2);
    countPeriod = 0;
    Try(1);
    printf("%d", count);
}