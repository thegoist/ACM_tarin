#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
const int MAXN = 17;

 ///'U', 'R', 'D' 'L'
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int M, N;
char G[MAXN][MAXN];
bool v[MAXN][MAXN][4];

void DFS(int k, int x, int y, int &ans)
{
		cout<<x<<y<<"  "<<ans<<" "<<G[x][y]<<endl;
    if(G[x][y] == '.')
    {
        ans += 1;
        G[x][y] = '#';
    }

    for(int i=0; i<4; i++)
    {
        int nx = x+dir[(i+k)%4][0];
        int ny = y+dir[(i+k)%4][1];

        if(nx>=0&&nx<M && ny>=0&&ny<N && G[nx][ny]!='*')
        {
            if(v[nx][ny][(i+k)%4] == true)
                break;
            v[nx][ny][(i+k)%4] = true;
            DFS((i+k)%4, nx, ny, ans);
            break;
        }
    }
}

int main()
{
    while(scanf("%d%d", &M, &N) != EOF)
    {
        memset(v, 0, sizeof(v));

        int x, y, op;

        for(int i=0; i<M; i++)
        {
            scanf("%s", G[i]);
            for(int j=0; j<N; j++)
            {
                if(G[i][j] == 'U')
                    op = 0, x=i, y=j;
                if(G[i][j] == 'R')
                    op = 1, x=i, y=j;
                if(G[i][j] == 'D')
                    op = 2, x=i, y=j;
                if(G[i][j] == 'L')
                    op = 3, x=i, y=j;
            }
        }

        int ans = 1;
        DFS(op, x, y, ans);

        printf("%d\n", ans);
    }

    return 0;
}
