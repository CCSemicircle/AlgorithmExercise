#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

const int MAXN=201;

bool visit[MAXN];

void BFS(int n){
	queue<long long> Q;
	Q.push(1);
	while(!Q.empty()){
		long long curr = Q.front();
		Q.pop();
		// 除以n有相同余数的只要遍历第一个即可，之后的可以跳过，减少遍历,防止超时 
		if(!visit[curr % n]){
			if(curr % n==0){
				printf("%lld\n",curr);
				return ;
			}
			visit[curr % n]=true;
			Q.push(curr*10);
			Q.push(curr*10+1);
		}	
	}
}

int main(){
	int n;
	while(scanf("%d",&n) && n){
		memset(visit,false,sizeof(visit)); 
		BFS(n);
	}
	return 0;
}
