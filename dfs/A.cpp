#include<cstdio>
/*
 �������ڵ�ˮƽ��DFS��ʱ���������� 
*/ 
//#include<bits/stdc++.h>
using namespace std;
int n = 0,k = 0;
int lines[1000005] = {0};
int book[1000005] = {0};
int minutes = 0;
int min1 = 99999;
void dfs(int x,int step){
	printf("%d \n",x);
	int move = 0;
	//�ҵ����� 
	if(lines[x] == 1){
		if(step<min1){
			min1 = step;
		}
		return ;
	}
	//�������������ƶ� 
	move = x + 1;
	if(book[move] == 0 && move <= 2*(k-n)){
		book[move] = 1;
		dfs(move,step+1);
		book[move] = 0;
	}
	move = x - 1;
	if(book[move] == 0 && move <= 2*(k-n)){
		book[move] = 1;
		dfs(move,step+1);
		book[move] = 0;
	}
	
	move = 2 * x;
	if(book[move] == 0 && move <= 2*(k-n)){
		book[move] = 1;
		dfs(move,step+1);
		book[move] = 0;
	}	 
	return ;
}
int main(){
	int step = 0;
	while((scanf("%d%d",&n,&k)) != EOF){
		min1 = 99999;
		lines[k] = 1;
		step = 0;
		book[0] = 1;
		dfs(n,step);
		printf("%d",min1); 
		
	}
	return 0;
}
