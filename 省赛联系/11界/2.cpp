#include<bits/stdc++.h>
using namespace std;
int is_prime(int a){
	if (a == 2) return 1;
    if (a % 2 == 0) return 0;
    int x = sqrt(a);
    for (int i = 2; i <= x; ++i){
        if (a%i == 0)return 0;
    }
    return 1;
}
int main(){
	int n;
	cin>>n;
	int x;
	for(int i = 1 ; i <= n ; i++){
		cin>>x;
		int flag1 = x+1;
		int flag2 = x-1;
		if(is_prime(x)){
			cout<<x<<endl;
		}else{
//			up 
			while(1){
				if(is_prime(flag1)){
					break;
				}
				flag1++;
			}
//			down
			
			while(1){
				if(is_prime(flag2)){
					break;
				}
				flag2--;
			}
		}
//		cout<<flag1<<" "<<flag2<<endl;
		int temp1,temp2;
		temp1 = flag1 - x;
		temp2 = x - flag2;
		if(temp2 == temp1) cout<<flag1<<endl;
		if(temp2<temp1){
			cout<<flag2<<endl;
		}else{
			cout<<flag1<<endl;
		}
	}
	return 0;
} 
