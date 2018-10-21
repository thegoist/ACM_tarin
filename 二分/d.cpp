#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int spends[100005] = {0};
int judge(int mid){
	int counter = 1;
	int sum = 0;
	for(int i = 0; i < n; i++){
		if(spends[i]>mid){
			return 0;
		}
		if(sum+spends[i]>mid){
			
			sum = spends[i];
			counter++;
		}else{
			sum += spends[i];
		}
	}
	if(counter>m){
		return 0;
	}else{
		return 1;
	}
	
}
int main(){
//	int ans = 0;
	while((scanf("%d%d",&n,&m)) != EOF){
		int r = 0,l = 0,mid = 0;
		int ans = 0;
		memset(spends, 0, sizeof(int)*100005);
		for(int i = 0; i < n; i++){
			scanf("%d",&spends[i]);
			r += spends[i];
//			if(l<spends[i]){
//				l = spends[i];
//			}
		}
	
//		r = 10000;
		
		while(l<=r){
			mid = (r+l)/2;
			if(judge(mid)){
				r = mid - 1;
//				printf("test1 l = %d    r = %d\n",l,r);
				ans = mid;
			}else{
				l = mid + 1;
//				printf("test2 l = %d    r = %d\n",l,r);
			}
		
		}
		printf("%d\n",ans);
//			printf("mid = %d  r = %d l = %d\n",mid,r,l);
	}
	return 0;
} 
