/**
 * liệt kê các hoán vị của 1,2,3,...,n
 * 
*/
#include <stdio.h>

#define MAX 100

int result[MAX];
int checkExist[MAX];
int n;

void printResult() {
    for(int i = 1; i<=n ; i++ ) {
        printf("%d,", result[i]);
    }
    printf("\n");
}

void hoanvi(int k){
    for(int i = 1; i<=n; i++){
        if(checkExist[i]==0) 
        {
            result[k] = i;
            checkExist[i] = 1;
            if(n==k) {
                printResult();
            }
            else
            {
                hoanvi(k+1);
            }
            checkExist[i] = 0;
            
        } 
        
    }
}

int main() {
    scanf("%d", &n);
    hoanvi(1);
    return 0;
}