#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
const int inf=99999999;
int mp[25][25];
int n;
int main(){
	
	while(scanf("%d",&n) != EOF){
		cout<<"   "<<n<<endl;
		for(int i = 0; i < 25; i++)
		for(int j = 0; j < 25; j++)
		mp[i][j] = inf;
		
	}
	return 0;
} 
