/* 
Ö©ÖëÖ½ÅÆ
*/ 
//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int ans ;
int a[15] = {0};
int book[15] = {0};

int abs(int num){
//	cout<<num<<endl;
	if(num < 0){
		return -num;
	}else{
		return num;
	}
}
void dfs(int cnt,int sum){
	
	if(sum>=ans){
		return ;
	}
	if(cnt == 9){
		ans = sum;
		return ;
	}
	for(int i = 1 ; i < 10; i++){
		if(!book[i]){
			book[i] = 1;
			for(int j = i+1;j<=10;j++){
				if(!book[j]){
					dfs(cnt+1,sum+abs(a[i]-a[j]));
					break;
				}
			}
			book[i] = 0;
		}
	}
}
int main(){
	int n = 0;
	int temp = 0;
	scanf("%d",&n);
	for(int j = 0; j < n; j++){
		for(int i = 0; i < 10 ; i++){
			scanf("%d",&temp);
			a[temp] = i;
			}
		memset(book,0,sizeof(book));
		ans = 10000000;
		dfs(0,0);
		printf("%d\n",ans);
	}
	

	return 0;
} 
