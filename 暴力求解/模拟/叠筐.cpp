#include<iostream>

using namespace std;

const int MAXN=80;

char arr[MAXN][MAXN];

int main(){
	char ch[2];
	int n;
	while(cin>>n>>ch[0]>>ch[1]){
		for(int i=0;i<n;i++){
			char c=ch[(i+1)%2];
		    // 找规律确定符号
			for(int j=i;j<n-i;j++){
				arr[i][j]=c;
				arr[n-1-i][j]=c;
				arr[j][i]=c;
				arr[j][n-1-i]=c;
			}
		}
		// 注意考虑只有1的情况
		if(n!=1){
			arr[0][0]=' ';
			arr[0][n-1]=' ';
			arr[n-1][0]=' ';
			arr[n-1][n-1]=' ';
		} 
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<arr[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
