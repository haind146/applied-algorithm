#include<bits/stdc++.h>
using namespace std;

const int N=(int) 3e6;
const int INF=(int)0x3f3f3f3f;
int n,L[N+10],R[N+10];

inline void Read(int &n){//Tang toc do doc du lieu dau vao so voi ham scanf
    char c;n=0;
    do{
        c=getchar();
    }while(!isdigit(c));
    do{
        n=n*10+c-48;
        c=getchar();
    }while(isdigit(c));
}
int main(){
    for(int i=0;i<=N+1;++i){
        L[i]=R[i]=-INF;

    }
    Read(n);
    while(n--){
        int s,t;
        Read(s);
        Read(t);
        L[t]=max(L[t],t-s);
        R[s]=max(R[s],t-s);

    }
    for(int i=1;i<=N;++i)L[i]=max(L[i-1],L[i]);
    for(int i=N;i>=1;--i)R[i]=max(R[i+1],R[i]);
    int ans=-INF;
    for(int i=1;i<=N-1;++i){
        ans=max(ans,L[i]+R[i+1]);
    }
    if(ans==-INF)ans=-1;
    printf("%d",ans);
    return 0;
}