#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int inf=999999;
int mp[1005][1005];
int home[100];
int want[100];
int t,s,d;
void floyd(){
	for(int k = 0; k < 1005; k++){
		for(int i = 0; i < 1005; i++){
			if(mp[i][k] == inf) continue;
			for(int j = 0; j < 1005; j++){
				mp[i][j] = min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
}
int main(){
	
	while(scanf("%d%d%d",&t,&s,&d) != EOF){
//		cout<<"   "<<n<<endl;
		//³õÊ¼»¯ 
		memset(mp,0,sizeof(mp));
		memset(home,0,sizeof(home));
		memset(want,0,sizeof(want));
		for(int i = 0; i < 1005; i++){
		for(int j = 0; j < 1005; j++){
			mp[i][j] = inf;
			if(i==j) mp[i][j] = 0;
		}
		}
		
		
		int tempX,tempY,tempDis;
		for(int i = 0 ;i < t; i++){
			cin>>tempX>>tempY>>tempDis;
			if(mp[tempX][tempY] > tempDis ){
				mp[tempX][tempY] = tempDis;
				mp[tempY][tempX] = tempDis;
//				cout<<tempX<<" "<< tempY<<" "<<tempDis;
			} 
		}
		
		int temp = 0;
		for(int i = 0 ; i < s; i++){
			cin>>home[i];
		}
		
		for(int i = 0 ; i < d; i++){
			cin>>want[i];
		}
		
		floyd();
		
		int sum = 0;
		int road = inf;
		for(int i = 0; i < s; i++){
			for(int j = 0; j < d; j++){
				
//				cout<<mp[home[i]][want[j]]<<endl;
				if(road > mp[home[i]][want[j]]) road = mp[home[i]][want[j]];
			}
		}
		cout<<road<<endl;
	}
	return 0;
} 
