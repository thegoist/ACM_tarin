#include<bits/stdc++.h>
using namespace std;
const int N=100010;
struct node{int l,r;} p[N];
int n,tot,num,a[N],w[N],L[N],R[N],f[N];
bool cmp(node x,node y)
{
    if(x.r!=y.r) return x.r<y.r;//???:??? 
    return x.l<y.l;//????:??? 
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x+y>=n) continue;//?????(????) 
        p[++tot].l=x+1,p[tot].r=n-y;//???????? 
    }
    sort(p+1,p+tot+1,cmp);
    for(int i=1;i<=tot;i++)//??????
    {
        if(p[i].l!=p[i-1].l||p[i].r!=p[i-1].r) num++;
        //?????????num??????,????
        w[num]=min(w[num]+1,p[i].r-p[i].l+1);//????
        L[num]=p[i].l,R[num]=p[i].r;//??????????
    }
    int j=1;
    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1];
        while(j<=num&&R[j]==i) 
        {
            f[i]=max(f[i],f[L[j]-1]+w[j]);//?????
            j++;
        }
    }
    printf("%d",n-f[n]);
    return 0;
}
