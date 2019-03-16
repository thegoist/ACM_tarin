#include<iostream>
using namespace std;
int n;
int a[205];
int s[205];
int f[205][205];
// f[i][j] = max(f[i][j],f[i][k]+f[k+1][j] + s[i] - s[j])
int main(){
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		scanf("%d",&a[i]);
		a[n+i] = a[i];
		s[i]=s[i-1]+a[i];
	}
	
//	int l = 0;
	
	for(int l = 2 ; l <= n ; l++){
		for(int i = 1 ; i <= n-l+1 ; i++){
			int j  = i+l-1;
			f[i][j] = 9999999;
			
			for(int k = i ; k < j ; k++){
				f[i][j] = min(f[i][j],f[i][k]+f[k+1][j] + s[j] - s[i-1]);
			}
		}
		
	}
	
	cout<<f[1][n]<<endl;	
	return 0;
}
