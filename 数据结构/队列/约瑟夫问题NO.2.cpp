#include<iostream>
#include<queue>

using namespace std;

int main(){
	int n,p,m;
	while(cin>>n>>p>>m){
		if(n==0 && p==0 && m==0){
			break;
		}
		queue<int> Q;
		// init
		for(int i=0;i<n;i++){
			Q.push(i+1);
		}
		for(int i=1;i<p;i++){
			int curr = Q.front();
			Q.pop();
			Q.push(curr);
		}
		// simulate
		int cnt=0;
		bool first = true;
		while(!Q.empty()) {
			int curr = Q.front();
			Q.pop();
			cnt++;
			if(cnt != m){
				Q.push(curr);
			}else{
				if(first){
					cout<<curr;
					first =false;
				}else{
					cout<<","<<curr;
				}
				cnt=0;
			}
		}
		cout<<endl;
	}
	return 0;
} 
