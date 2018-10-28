//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
char mp[205][205];
int book[205][205];
int n,m;
int Y_x,Y_y,M_x,M_y;
int kfc_x,kfc_y;

//int step;
int min1 = 99999999;
void dfs(int x,int y,int step){
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	int tx,ty;
//	cout<< x<< " "<< y<<endl;
	if(mp[x][y]=='@'){
//		cout<<step<<endl;
		
		if(step<min1){
			min1 = step;
			return ;
		}
	}
	for(int i = 0; i<4;i++){
		tx = x+next[i][0];
		ty = y+next[i][1];
		
		if(tx<0 || tx>n || ty<0 || ty>m){
			continue;
		}
		if((mp[tx][ty]=='.' || mp[tx][ty]=='@') && book[tx][ty]==0){
			book[tx][ty] = 1;
			dfs(tx,ty,step+1);
			book[tx][ty] = 0;
		}
	}
	return ;
}
int main(){

	while(scanf("%d%d",&n,&m) != EOF){
//		cout<<n<<m<<endl;
		for(int i = 0; i < n;i++){
			for(int j = 0; j < m; j++){
				cin>>mp[i][j];
				if(mp[i][j] == 'Y'){
					Y_x = i;
					Y_y = j;
				}else if(mp[i][j] == 'M'){
					M_x = i;
					M_y = j;
				}
//				else if(mp[i][j] == '@'){
//					kfc_x = i;
//					kfc_y = j;
////					cout<<i<<" "<<j<<endl;
//				}
			}
		}
		
//		for(int i = 0; i < n;i++){
//			for(int j = 0; j < m; j++){
//				cout<<mp[i][j]; 
//			}
//			cout<<endl;
//		}

//		cout<<M_x<<M_y<<endl;
		min1 = 99999999;
		dfs(Y_x,Y_y,0);
		int Y_time = min1*11;
		
		min1 = 99999999;
		dfs(M_x,M_y,0);
		int M_time = min1*11;
		
		cout<<M_time+Y_time<<endl;
		


	}
	return 0;
}
