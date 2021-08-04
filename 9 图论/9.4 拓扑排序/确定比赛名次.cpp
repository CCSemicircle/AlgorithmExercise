#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

const int MAXN=501;

vector<int> graph[MAXN];
int inDegree[MAXN];
int ans[MAXN];

void TopologicalSort(int n){
	// 使用优先队列存储，保证编号小的在前面 
	priority_queue<int,vector<int>, greater<int> > node;
	// 注意编号从1到n 
	for(int i=1;i<=n;i++){
		if(inDegree[i]==0){
			node.push(i);
		}
	}
	int number=0;
	while(!node.empty()){
		int u = node.top();
		ans[number++]=u;
		node.pop();
		for(int i=0;i<graph[u].size();i++){
			int v = graph[u][i];
			inDegree[v]--;
			if(inDegree[v]==0){
				node.push(v);
			}
		}
	}
}


int main(){
	int n,m;
	while(cin>>n>>m){
		memset(graph,0,sizeof(graph));
		memset(inDegree,0,sizeof(inDegree));
		for(int i=0;i<m;i++){
			int from,to;
			cin>>from>>to;
			graph[from].push_back(to);
			inDegree[to]++;
		}
		TopologicalSort(n);
		// 保证最后一名后无空格，所以此处只遍历到n-2 
		for(int i=0;i<n-1;i++){
			cout<<ans[i]<<" ";
		}
		cout<<ans[n-1]<<endl;
	}
	return 0;
}
