//POJ 1088
#include<iostream>
#include<algorithm>
using namespace std;
int r,c;
int mp[105][105];
int book[105][105];
int dp[105][105];
int mx = 0;
int mn = 10005;
int x1,y1,x2,y2;

int dfs(int x,int y){
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //�ĸ����� 
	int tx,ty;
	
	//���仯���� 
	if(dp[x][y]) return dp[x][y];
	
	//��εĲ��� 
	int ret = 1;
	
	for(int i = 0; i<4;i++){
		tx = x+next[i][0];
		ty = y+next[i][1];
		//�жϱ߽����� 
		if(tx<1 || tx>r || ty<1 || ty>c){
			continue;
		}
		//����õ�����ߣ���ǲ�������һ�ε�DFS 
		if(book[tx][ty]==0 && mp[tx][ty]<mp[x][y]){
			book[tx][ty] = 1;
			ret = max(dfs(tx,ty)+1, ret);
			book[tx][ty] = 0;
		}
	}
	dp[x][y] = ret;
	return ret;
}

int main(){
	cin>>r>>c;
	for(int i = 1 ; i <= r ; i++){
		for(int j = 1; j <= c ; j++){
			scanf("%d",&mp[i][j]); 
		}
	}
//	cout<<mx<<" "<<mn<<endl;
	int ans = 0;
	for(int i = 1 ; i <= r ; i++){
		for(int j = 1 ; j <= c ; j++){
			//���ÿһ���� 
			ans = max(dfs(i,j), ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}
