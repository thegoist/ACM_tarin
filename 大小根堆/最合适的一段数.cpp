#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int h[101];
void swap(int x, int y){
	int t;
	t=h[x];
	h[x]=h[y];
	h[y]=t;
	return ;
}
void siftdown(int i)   //n/2 log 2 n µÄ¸´ÔÓ¶ÈÐ¡
{
	int t,flag=0;
	while(flag==0&&i*2<=n){
		if(h[i]<h[i*2])	t=i*2;
		else t=i; 
		if(i*2+1<=n){
			if(h[t]<h[i*2+1])
				t=i*2+1;
		}
		if(t!=i){
			swap(t,i);
			i=t;
		}
		else{
			flag=1;
		} 
	}
	return ;
}

void creat()
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		siftdown(i);
	}
	return ;
}

void heapsort(){
	while(n>1){
		swap(1,n);
		n--;
		siftdown(1);
	}
	return ;
}

int main(){
	cin>>n>>m;
//	cout<<n<<endl;
	for(int i = 1 ; i <= n ; i++){
		scanf("%d",&h[i]);
	}
//cout<<n<<endl;6 3
	int num = n;
	creat();
	heapsort();
	int min_df = 99999;
	int flag = 1;
	for(int i=1;i<=num;i++){
		cout<<h[i]<<" ";
//		if(h[i+m-1] - h[i] < min_df){
//			min_df = h[i+m-1] - h[i];
////			flag = i; 
//		}	
	}
//	cout<<min_df<<endl;
		
	
	return 0;
}




