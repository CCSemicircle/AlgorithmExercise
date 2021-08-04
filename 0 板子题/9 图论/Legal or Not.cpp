#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

const int MAXN=101;

vector<int> graph[MAXN];
int inDegree[MAXN];

bool TopologicalSort(int n){
	queue<int> node;  // 入度为0的顶点队列 
	for(int i=0;i<n;i++){
		if(inDegree[i]==0){
			node.push(i);
		}
	} 
	int number=0;  // 结点序列 
	while(!node.empty()){
		number++;
		int u = node.front();
		node.pop();
		for(int i=0;i<graph[u].size();i++){
			int v = graph[u][i];
			inDegree[v]--;  // 以u为起点的边的终点入度减一 
			if(inDegree[v]==0){
				node.push(v);
			}
		}
	}
	return n == number;
}

int main(){
	int n,m;
	while(cin>>n>>m){
		if(n==0 && m==0){
			break;
		}
		memset(graph,0,sizeof(graph));
		memset(inDegree,0,sizeof(inDegree));
		for(int i=0;i<m;i++){
			int from,to;
			cin>>from>>to;
			graph[from].push_back(to);
			inDegree[to]++; 
		} 
		if(TopologicalSort(n)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}
