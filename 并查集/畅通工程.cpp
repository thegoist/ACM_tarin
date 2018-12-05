#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int f[1005];
void init(){
	for(int i = 0 ; i < 1005 ; i++){
		f[i] = i;
	}
}

int getf(int v){
	if(f[v] == v){
		return v;
	}else{
		f[v] = getf(f[v]);
		return f[v];
	}
}
void merge(int x, int y){
	int t1,t2;
	t1 = getf(x);
	t2 = getf(y);
	if(t1 != t2){
		f[t2] = t1;
	}
}
int main(){
	int n,m;
	int x,y;
	while(scanf("%d %d",&n,&m) != EOF){
		if(n == 0) break;
		init();
//		memset(f,0,sizeof(f));
		for(int i = 0 ; i < m; i++){
			scanf("%d %d",&x,&y);
//			if(f[x] == 0) f[x] = x;
//			if(f[y] == 0) f[y] = y;
			merge(x,y);
		}
		int cnt = 0;
		for(int i = 1 ; i <= n ; i++){
			if(f[i] != 0){
				if(f[i] == i){
					cnt++;
				}
			}
		}
		printf("%d\n",cnt-1);
	}
	
} 
