#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int l,n,m,a[50003],ans;//�������
int count(int mid)
{
    int j=0,x=0;//x��¼ɾȥʯͷ��
    for(int i=1;i<=n+1;i++)
    {
        if(a[i]-a[j] < mid)//ʯͷ��������С��ö�ٵģ��ͼ�¼��ɾȥ��
        x++;
        else j=i;//�����ƶ���㡣
    }
    return x;
}
int main()
{
    scanf("%d%d%d",&l,&n,&m);
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    sort(a+1,a+1+n); //����������
    a[n+1]=l;//��¼�յ�
    int left=1,right=l;
    while(left<=right)//��ʼ���֡�
    {
        int middle=(left+right)/2;
        if(count(middle)<=m)//��������
        {
        ans=middle;
        left=middle+1;  
        } 
        else right=middle-1;
    }
    printf("%d",ans);//���
    return 0;
}
