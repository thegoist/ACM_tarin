#include<stdio.h>
#include<math.h>
int main(){
	float x1,y1,x2,y2;
	float dis;
	while((scanf("%f%f%f%f",&x1,&y1,&x2,&y2)) != EOF){
		dis = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
		printf("%.2lf\n",dis);
	}
	return 0;
} 
