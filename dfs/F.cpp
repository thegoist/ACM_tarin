#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char a[15][15];
//int book[15][15];
bool book2[15][15][4];
int w,h;
int mx = 0;
int start_x,start_y;
int next_p[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int ans = 1;
 
void dfs(int x,int y,int d,int &step){
	int nx,ny;
	ans = step;
	cout<<x<<y<<"  "<<step<<" "<<a[x][y]<<ans<<endl;
	if (a[x][y] == '.')
	{
		step+=1;
		a[x][y] = '#';
//		ans = step;
//		cout<<" "<<step<<endl;
	}

	for (int i = 0; i < 4; i++)
	{
//		if(((i+d)%4)==0){
//			nx = x+next_p[]
//		}
		nx = x+next_p[(i+d)%4][0];
		ny = y+next_p[(i+d)%4][1];

		if (nx>=0 && nx<w && ny>=0 && ny<h && a[nx][ny]!='*')
		{
			if(book2[nx][ny][(i+d)%4] == true)
				break ;
			
			book2[nx][ny][(i+d)%4]= true ;
			dfs(nx,ny,(i+d)%4,step);
			break ;
			
		}
	
	}
}
int main()
{
	
//	int ans = 0;
	while(scanf("%d%d",&w,&h) != EOF){
	memset(book2, 0, sizeof(book2));
//	memset(book, 0, sizeof(book));
	memset(a, 0, sizeof(a));
	start_x = 0 ,start_y = 0;
//	flag = 0;
	mx = 0;
	ans = 0;
		// cout<<w<<h<<endl;
		//read 
		mx = 0;
		int op = 0;
		for (int i = 0; i < w; i++)
		{
			scanf("%s",a[i]);
			for (int j = 0; j < h; j++)
			{
				if(a[i][j] == 'U')
                    op = 0, start_x=i, start_y=j;
                if(a[i][j] == 'R')
                    op = 1, start_x=i, start_y=j;
                if(a[i][j] == 'D')
                    op = 2, start_x=i, start_y=j;
                if(a[i][j] == 'L')
                    op = 3, start_x=i, start_y=j;
			}
		}

//		book[start_x][start_x] = 0;

		int step = 1;
		dfs(start_x,start_y,op,step);
		printf("%d\n",step);
		
//		for(int i = 0; i<w;i++){
//			for(int j = 0; j<h;j++){
//				if(book2[i][j] == 1){
//					ans++;
//				}
//			}
////			cout<<endl;
//		}

	}
	return 0;
}
