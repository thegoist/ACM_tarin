
//////////////////////
//向下调整
void siftdown(int i)
{
	int t,flag=0;
	while(i*2<=n&&flag==0)
	{
		if(h[i]>h[i*2])
			t=i*2;
		else
			t=i;
		if((i*2+1)<=n)
		{
			if(h[t]>h[i*2+1])
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
/////////////向上调整
void siftup(int i)
{
	int flag=0;
	if(i==1)
		return;
	while(i!=1&&flag==0)
	{
		if(h[i]<h[i/2])
			swap(i,i/2);
		else
			flag=1;
		i=i/2;
	}
	return ;
}

///////////**//////////////////////////////////////////////
#include<stdio.h>
int h[101];
int n;
void swap(int x,int y)
{
	int t;
	t=h[x];
	h[x]=h[y];
	h[y]=t;
	return;
}
void siftdown(int i)             ////向下调整从顶点开始
{
	int t,flag=0;            ////flag用来标记是否继续调整
	while(i*2<=n&&flag==0)       //至少i有左儿子并需要调整
	{
		if(h[i]>h[i*2])    //首先判断他和左儿子的关系取最小
			t=i*2;
		else
			t=i;
		if(i*2+1<=n)       //然后判断他和右儿子的关系
		{
			if(h[t]>h[i*2+1])
				t=i*2+1;         //取最小
		}
		if(t!=i)
		{
			swap(t,i);           //若发现最小节点标号不是自己说明子节点有比父节点小的
			i=t;   //向下调整
		}
		else
			flag=1;//说明父节点已经是最小的了
	}
	return ;
}
void creat()
{
	int i;
	//从最后一个非叶节点到第一个节点依次下降
	for(i=n/2;i>=1;i--)
	{
		siftdown(i);
	}
	return ;
}
int delemax()       ///删除最大的元素
{
	int t;
	t=h[1];     
	h[1]=h[n];        //将堆的最后一个点赋值到堆顶
	n--;
	siftdown(1);    //向下调整
	return t;         //返回之前记录的最小值 
}
int main()
{
	int i,num;
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	scanf("%d",&h[i]);
	n=num;
	creat();             //建堆
	for(i=1;i<=num;i++)
	{
		printf("%d, ",delemax());
	}
	getchar();
}
///
//使用堆进行排序  注意建堆不等于排序
#include<stdio.h>
int h[101];
int n;
void swap(int x,int y)
{
	int t;
	t=h[x];
	h[x]=h[y];
	h[y]=t;
	return ;
}
void siftdown(int i)   //n/2 log 2 n 的复杂度小
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
	int i,num;
	scanf("%d",&num);
	for(i=1;i<=num;i++)
		scanf("%d",&h[i]);
	n=num;
	creat();
	heapsort();
	for(i=1;i<=num;i++)
		printf("%d ",h[i]);
	getchar();
	return 0;
}
//
