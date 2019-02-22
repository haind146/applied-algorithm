#include<stdio.h>
#define MAX 100
int x[MAX],a[MAX];
int n,M;
int count=0;
int T;
void solution(){
//	printf("\n%d",T);
	if(T==M){
		count++;
	}
	
}
void input(){	
	scanf("%d",&n);
	scanf("%d",&M);
	
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	
//		printf ("%d.%d",i,a[i]);
	}

}
bool check (int v,int k){
	return T+a[k]*v<=M; 
}
void Try(int k){
	for(int v=1;v<=M/a[k];v++){
		if(check(v,k)){
			x[k]=v;
			T+=a[k]*v;
			if(k==n){
				solution();
			}
			else Try(k+1); 
			T-=a[k]*v;
		}
		
		
	}
}
void solve(){
	count=0;
	Try(1);
	T=0;
}
int main(){
	input();
	solve();
	printf("%d",count);
}