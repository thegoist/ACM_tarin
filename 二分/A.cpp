#include<cstdio>
using namespace std;
int N,K;
long long num[10005] = {0};
int judge(long long x){
	int sum = 0;
	for(int i = 0; i < N;i++){
		sum += num[i]/x;
	}
	if(sum >= K){
		return 1;
	}else{
		return 0;
	}
} 
int main(){ 
	double temp ;
	long long mid = 0;
	double r = 0, l = 0;
	double out ;
	while((scanf("%d%d",&N,&K)) != EOF){
//		printf("%d  %d\n",N,K);
		for(int i = 0; i < N; i++ ){
			scanf("%lf",&temp);
			num[i] = temp * 100;
		}
		l = 0;
		r = 10000000000;
		for(int i = 0 ; i < 100; i++){
			mid = (r+l)/2;
//			printf("mid == %d\n",mid);
			
			if(mid==0) { 
			    l = mid;
			  break;}
			if(judge(mid)){
				l = mid ;
			}else{
				r = mid ;
			}
			
		}
		out = l / 100;
		printf("%.2lf\n",out);
	}
	
	return 0;
}
