#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct node{
	int l;
	int r;
}p[1000001];
int w[1000001],L[1000001],R[1000001],f[1000001];

bool cmp(node x , node y){
	if(y.r != x.r) return x.r<y.r;
	return x.l<y.l;
}
int main(){
	cin>>n;
	int num = 1;
	for(int i = 1 ; i <= n; i++){
		int x,y;
		cin>>x>>y;
		if(x+y > n) continue;
		
		p[num].l = x+1;
		p[num].r = n-y;
		num++;
	}
	
	sort(p+1,p+num+1,cmp);
	
	int tot = 0 ; 
	for(int i = 1 ; i <= num; i++){
		if(p[i].l!=p[i-1].l || p[i].r!=p[i-1].r) tot++;
		w[tot] = min(w[tot]+1,p[i].r - p[i].l + 1);
		L[tot] = p[i].l;
		R[tot] = p[i].r;
	}
	int j = 1;
	for(int i = 1 ; i <= n ; i++){
		f[i] = f[i-1];
		while(j<=tot && R[j] == i){
			f[i] = max(f[i], f[L[j]-1]+w[j]);
			j++;
		}
	}
	cout<<n-f[n]<<endl;
	return 0;
}
