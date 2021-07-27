#include<iostream>

using namespace std;

long long Function(int n){
	if(n==1){
		return 2;
	}else{
		// 考虑将最大圆盘从第一根杆移动到第三根杆即可得到如下关系 
		return 3*Function(n-1)+2;
	} 
}

int main(){
	int n;
	while(cin>>n){
		cout<<Function(n)<<endl;
	}
	return 0;
} 
