#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int h[101];
int x;
void swap(int x,int y)
{
	int t;
	t=h[x];
	h[x]=h[y];
	h[y]=t;
	return ;
}
void siftdown(int i)   //n/2 log 2 n µÄ¸´ÔÓ¶ÈÐ¡
{
	int t,flag=0;
	while(flag==0&&i*2<=n)
	{
		if(h[i]<h[i*2])
			t=i*2;
		else
			 t=i;
		if(i*2+1<=n)
		{
			if(h[t]<h[i*2+1])
				t=i*2+1;
		}
		if(t!=i)
		{
			swap(t,i);
			i=t;
		}
		else
			flag=1;
	}
	return ;
}

void creat()
{
	int i;
	for(i=x/2;i>=1;i--)
	{
		siftdown(i);
	}
	return ;
}
void heapsort(){
	while(x>1)
	{
		swap(1,x);
		x--;
		siftdown(1);
	}
	return ;
}
int main()
{
	int num;
	int nums;
	int a[101] = {0};
//	scanf("%d",&num);
	cin>>num>>nums;
	for(int i=1;i<=num;i++){
		scanf("%d",&a[i]);
	}
//	n=num;
//	x = nums;
//	cout<<x<<endl;
	int min_df = 999999;
	for(int i = 1; i <= num - 2 ; i++){
		for(int j = 1 ; j <= nums; j++){
			
			h[j] = a[i+j-1];
			cout<<h[j]<<" ";
		}
		x = nums;
		n = num;
		cout<<endl;
		creat();
		heapsort();
		cout<<"changed:  ";
		for(int j = 1 ; j <= nums; j++){
			cout<<h[j]<<" ";
		}
		cout<<endl;
		
		
	}
		
		cout<<min_df<<endl;


	return 0;
		
	}
//	1  5  4  7  10  16
		


