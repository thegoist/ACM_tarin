#include<stdio.h>
#include<iostream>
using namespace std;
int h[101];
int a[101];
int n,x;
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
	for(i=n/2;i>=1;i--)
	{
		siftdown(i);
	}
	return ;
}
void heapsort(){
	while(n>1)
	{
		swap(1,n);
		n--;
		siftdown(1);
	}
	return ;
}
int main()
{
	int num;
	int nums;
	int min_df = 99999;
	cin>>num>>nums;
//	scanf("%d",&num);
	for(int i=1;i<=num;i++)
		scanf("%d",&a[i]);
		
	for(int i = 1 ; i <= num ; i++){
		for(int j = 1 ; j <= nums ; j++){
			h[j] = a[i+j-1];
//			cout<<h[j]<<" ";
		}
//		cout<<endl;
		n=nums;
//		x=nums;
		creat();
		heapsort();
		
		if (min_df > h[nums] - h[1]) min_df = h[nums] - h[1]; 
//		for(int j=1;j<=nums;j++) cout<<h[j];
//		cout<<endl;
	}
	cout<<min_df<<endl;
	
	
	getchar();
	return 0;
}
