
//////////////////////
//���µ���
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
/////////////���ϵ���
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
void siftdown(int i)             ////���µ����Ӷ��㿪ʼ
{
	int t,flag=0;            ////flag��������Ƿ��������
	while(i*2<=n&&flag==0)       //����i������Ӳ���Ҫ����
	{
		if(h[i]>h[i*2])    //�����ж���������ӵĹ�ϵȡ��С
			t=i*2;
		else
			t=i;
		if(i*2+1<=n)       //Ȼ���ж������Ҷ��ӵĹ�ϵ
		{
			if(h[t]>h[i*2+1])
				t=i*2+1;         //ȡ��С
		}
		if(t!=i)
		{
			swap(t,i);           //��������С�ڵ��Ų����Լ�˵���ӽڵ��бȸ��ڵ�С��
			i=t;   //���µ���
		}
		else
			flag=1;//˵�����ڵ��Ѿ�����С����
	}
	return ;
}
void creat()
{
	int i;
	//�����һ����Ҷ�ڵ㵽��һ���ڵ������½�
	for(i=n/2;i>=1;i--)
	{
		siftdown(i);
	}
	return ;
}
int delemax()       ///ɾ������Ԫ��
{
	int t;
	t=h[1];     
	h[1]=h[n];        //���ѵ����һ���㸳ֵ���Ѷ�
	n--;
	siftdown(1);    //���µ���
	return t;         //����֮ǰ��¼����Сֵ 
}
int main()
{
	int i,num;
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	scanf("%d",&h[i]);
	n=num;
	creat();             //����
	for(i=1;i<=num;i++)
	{
		printf("%d, ",delemax());
	}
	getchar();
}
///
//ʹ�öѽ�������  ע�⽨�Ѳ���������
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
void siftdown(int i)   //n/2 log 2 n �ĸ��Ӷ�С
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
