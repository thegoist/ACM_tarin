#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n = 0,k = 0;
int mp[100005];
int next1[2] = {-1,1};
struct node{
	int x;
	int step;
};
void bfs(){
	int flag = 0;
	node start;
	int nx;
	node temp1;
	node temp2;
	start.step = 0;
	start.x = n;
	queue<node> q;
	q.push(start);
	while(!q.empty()){
		temp1 = q.front();
		q.pop();
		//三个方向 
		for(int i = 0; i < 3; i++){
			temp2 = temp1;
			if(i==2){
				temp2.x = temp2.x*2;
			}else{
				temp2.x += next1[i];
			}
			temp2.step = temp1.step+1;
			
			//超出边界了 pass
			if(temp2.x<0||temp2.x>100000||mp[temp2.x]){
				continue;
			}
			//如果找到了 
			if(temp2.x==k){
				flag = 1;
				cout<<temp2.step<<endl;
				break;
			}
			
//			cout<<temp2.x<<" "<<temp2.step<<endl;
			mp[temp2.x] = 1;
			q.push(temp2);
			 
		}
		if(flag == 1){
			break;
		}
		
	}

	
	
}
int main(){
	while((scanf("%d%d",&n,&k)) != EOF){
		memset(mp,0,sizeof(mp));
		mp[n] = 1;
		if(n==k){
			cout<<0<<endl;
		}else{
			bfs();
		}
//		mp[k] = 1;
			
	}
	return 0;
}
