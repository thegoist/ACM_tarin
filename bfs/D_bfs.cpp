#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
//already ac
using namespace std;
int n , m;
int Y_x,Y_y,M_x,M_y;
int next_p[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
char mp[205][205] = {0};

struct node{
	int x;
	int y;
	int step;
};
void bfs(int x,int y,int book[][205]){
	node start,now,temp;
	start.x = x;
	start.y = y;
	start.step = 0;
	queue<node> q;
	q.push(start);
	while(!q.empty()){
		now = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			temp = now;
			temp.x = now.x+next_p[i][0];
			temp.y = now.y+next_p[i][1];
			temp.step++;
			
			if(temp.x<0||temp.x>200||temp.y<0||temp.y>200||book[temp.x][temp.y]||mp[temp.x][temp.y]=='#'){
				continue;
			}
			if(mp[temp.x][temp.y] == '@'){
				book[temp.x][temp.y] = temp.step*11; 
			}else{
				book[temp.x][temp.y] = 1;
			}
			q.push(temp);
		}
		
		
	}
}
int main(){
	while(scanf("%d%d",&n,&m) != EOF){
		memset(mp,0,sizeof(mp));
		//read and mark y and m
		for(int i = 0; i < n; i++){
			scanf("%s",mp[i]);
			for(int j = 0; j < m; j++){
				if(mp[i][j] == 'Y'){
					Y_x = i;
					Y_y = j;
				}else if(mp[i][j] == 'M'){
					M_x = i;
					M_y = j;
				}
			}
		}
		
		//process data
		int min = 999999;
		int temp;
		int M_book[205][205] = {0};
		int Y_book[205][205] = {0};
		bfs(Y_x,Y_y,Y_book);
		bfs(M_x,M_y,M_book);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(Y_book[i][j]>1 && M_book[i][j]>1){
					temp = Y_book[i][j] + M_book[i][j];
					if(temp<min){
						min = temp;
					}
				}
			}
		}
		cout<<min<<endl;
		
		
	}
	return 0;
}
