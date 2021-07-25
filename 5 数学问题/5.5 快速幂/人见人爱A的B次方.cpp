#include<iostream>

using namespace std;

int fastExp(int a, int b, int mod){
	int ans=1;
	while(b){
		if(b%2 == 1){
			ans *= a;
			ans %= mod;
		}
		a *= a;
		a %= mod;
		b /= 2;
	}
	return ans;
}

int main(){
	int a,b;
	while(cin>>a>>b){
		if(a ==0 && b==0) break;
		cout<<fastExp(a, b , 1000)<<endl;
	}
	return 0;
} 
