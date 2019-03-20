#include <stack>
#include <stdio.h>
#include <string.h>

using namespace std;

int n;
char temp;
char line[100000];

int main() {
    stack<char> S;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s", line);
        int len = strlen(line);
        bool flag = true;
        for(int j=0;j<len;j++) {
            temp = line[j];
            if (temp == '(' || temp == '[' ||  temp == '{') { S.push(temp); }
            else {
                if(S.empty()) {
                    flag = false;
                    break;
                }
                if(temp == ')' && S.top() == '(' || temp == ']' && S.top() == '[' || temp == '}' && S.top() == '{' ) {
                    S.pop();
                    continue;
                } 
                else
                {
                    printf("0\n");
                    flag=false;
                    break;
                }
            }
        }
        if (S.size() != 0) {
            if (flag) {
                printf("0\n");
            }
            
        }else
        {
            printf("1\n");
        }
        while(!S.empty()){
            S.pop();
        }
        
    }
}