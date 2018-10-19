#include<cstdio>
#include<algorithm> 
using namespace std;
int a[100005] = {0};
int N;
int nums;
int judge(long long mid){
	int counter = 0;
	int num;
	for(int i = 0; i < N; i++){
		num = upper_bound(a,a+N,a[i]+mid) - a;
		counter += num - i - 1;
	}
	if(counter>=(nums+1)/2){
		return 1;
	}else{
		return 0;	
	}
}
int main(){
	
	long long l,r,mid = 0;
	
	while((	scanf("%d",&N)) != EOF){
		int ans = 0;	
		nums = ((N-1)*N)/2;
		for(int i = 0; i < N; i++){
		scanf("%d",&a[i]);
		}

		sort(a,a+N);
	
		l = 0;
		r = a[N-1] - a[0];
		while(l<=r){
			mid = (l+r)/2;
			if(judge(mid)){
        	    r = mid-1;
				ans = mid;
			}else{
				l = mid + 1;
			}
//			printf("%d\n",ans);
		}
//	for(int i = 0; i < N; i++){
//		printf("%d\n",a[i]);
//	}
		printf("%d\n",ans);
	}

	
	return 0 ;
}
