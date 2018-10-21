#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int l,n,m,a[50003],ans;//定义变量
int count(int mid)
{
    int j=0,x=0;//x记录删去石头数
    for(int i=1;i<=n+1;i++)
    {
        if(a[i]-a[j] < mid)//石头间距离如果小于枚举的，就记录并删去。
        x++;
        else j=i;//否则移动起点。
    }
    return x;
}
int main()
{
    scanf("%d%d%d",&l,&n,&m);
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    sort(a+1,a+1+n); //别忘了排序。
    a[n+1]=l;//记录终点
    int left=1,right=l;
    while(left<=right)//开始二分。
    {
        int middle=(left+right)/2;
        if(count(middle)<=m)//计数函数
        {
        ans=middle;
        left=middle+1;  
        } 
        else right=middle-1;
    }
    printf("%d",ans);//输出
    return 0;
}
