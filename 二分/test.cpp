#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int num[10010];
bool judge(int mid,int n,int k){
	int ans=0;
	if(mid==0)return false;
	for(int i=0;i<n;++i){
		ans+=num[i]/mid;
	}
	return ans>=k;
}
int main()
{
	int n,i,j,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		double len;
		int maxn=0;
		for(i=0;i<n;++i){
			scanf("%lf",&len);
			num[i]=(int)(len*100);
			maxn=max(maxn,num[i]);
		}
		bool flag=false;
		int l=0,r=maxn,ans;
		while(l<=r){
			int mid=(l+r)>>1;
			if(judge(mid,n,k)){
				ans=mid;
				flag=true;
				l=mid+1;
			}
			else {
				r=mid-1;
			}
		}
		if(flag){
			printf("%.2lf\n",ans*0.01);
		}
		else {
			printf("0.00\n");
		}
	}
	return 0;
}

