#include<cstdio>
#include<algorithm>
using namespace std;
int n,l,m;
long long a[50010] = {0};
int judge(int mid){
	int counter = 0;
	int before = 0;
	for(int i = 1; i <= n+1;i++){
		if((a[i] - a[before]) <mid){
			counter++;
		}else{
			before = i;
		}
	}
//	int j=0,x=0;//x��¼ɾȥʯͷ��
//    for(int i=1;i<=n+1;i++)
//    {
//        if(a[i]-a[j] < mid)//ʯͷ��������С��ö�ٵģ��ͼ�¼��ɾȥ��
//        x++;
//        else j=i;//�����ƶ���㡣
//    }

	if(counter <= m){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	int L = 0,R =0;
//	int mid = 0 ;
	int ans = 0;
	while((scanf("%d%d%d",&l,&n,&m)) != EOF){
		for(int i = 1; i <= n; i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		a[n+1] = l;
//		for(int i = 0; i<=n;i++){
//			printf("%d\n",a[i]);
//		}
		L = 1,R = l;
		while(L<=R){
			int mid = (L+R)/2;
			if(judge(mid)){
				ans = mid;
				L = mid + 1;
			}else{
				R = mid - 1;
			}
//		printf("ans %d  L %d  R %d\n",ans,L,R);
		}
		printf("%d\n",ans); 
		 
		
	}
	
	return 0 ;
} 
