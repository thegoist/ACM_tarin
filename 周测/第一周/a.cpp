//poj 2456

#include<iostream>
#include<algorithm> 
using namespace std;
int N,C;
int a[100005] = {0};
int judge(int x){
//	cout<<x<<endl;
	int counter = 1;
	int before = 1;
	
	int tmp = a[1];
	for(int i = 2 ; i <= N; i++){
		if(a[i]>=tmp+x){
			tmp = a[i];
			counter++;
//			cout<<"counter "<<counter<<" i "<<a[i]<<endl;
//			cout<<"a[i] a[before] counter: "<<a[i]<<" "<<a[before]<<" "<<counter<<endl;
			before = i;
		}
	}
	
	if(counter >= C){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	
	scanf("%d %d",&N,&C);
//	cout<<N<<C;
	for(int i = 1 ; i <= N ; i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+N+1);
	long long l,r;
	long long ans;
	l = 1;
	r = 1000000005;
	while(l<=r){
		long long mid = (l+r)/2;
//		cout<<"mid "<<mid<<endl;
		if(judge(mid)==1){
			ans = mid;
//			cout<<"ans: "<<ans<<endl;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
