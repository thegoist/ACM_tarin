#include<cstdio>
#include<algorithm>
using namespace std;
int n,l,m;
int a[50005] = {0};
int judge(int mid){
	int counter = 0;
	for(int i = 0; i < n;i++){
		
	}
	if(counter <= m){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	int L = 0,R =0;
	int mid = 0 ;
	int ans = 0;
	while((scanf("%d%d%d",&l,&n,&m))){
		for(int i = 0; i < n; i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		while(L<=R){
			mid = (L+R)/2;
			if(judge(mid)){
				ans = mid;
				L = mid + 1;
			}else{
				R = mid - 1;
			}
		}
		
		printf("%d\n")
		 
		
	}
	
	return 0 ;
} 
