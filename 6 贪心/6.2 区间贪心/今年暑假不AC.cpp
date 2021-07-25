#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN=101;

struct Program{
	int start;
	int end;
};


bool Compare(Program x, Program y){
	return x.end < y.end;
}

int main(){
	int n;
	Program programs[MAXN];
	while(cin>>n && n){
		for(int i=0;i<n;i++){
			cin>>programs[i].start>>programs[i].end;
		}
		sort(programs,programs+n,Compare);
		int curr=0,cnt=0;
		for(int i=0;i<n;i++){
			if(programs[i].start >= curr){
				curr = programs[i].end;
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
