#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//int dp[10010] ;
int  v[100002];
int main(){
	int t;
//	vector<int> dp;
//	vector<int> v;
	while(scanf("%d",&t) != EOF){
		for(int j = 0 ; j < t ; j++){
			
		int n;
		cin>>n;
		//这个地方 数组开小了 
		for(int i = 0 ; i < n ; i++){
			scanf("%d",&v[i]);
		}
		
		//dp[0] = v[0];
		int mx = -1001,first = 0,last = 0 ,temp = 1; 
		int sum = 0;
		for(int i = 0 ; i < n ;i++){
			//dp[i] = max(v[i] , dp[i-1] + v[i]);
			sum += v[i];
			if(sum > mx){
				mx = sum;
				first = temp;
				last = i+1;
			}
			if(sum < 0){
				sum = 0;
				temp = i+2;
			}
		}
		
		

		
			cout<<"Case "<<j+1<<":"<<endl;
			cout<<mx<<" "<<first<<" "<<last<<endl;
			if(j != t-1){
				cout<<endl;
			}
		}	
	}
		
	return 0;
}
