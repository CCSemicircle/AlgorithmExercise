#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<climits>

using namespace std; 

struct Edge{
	int to;
	int length;
	Edge(int t,int l):to(t),length(l){}
};

const int MAXN=1001;
const int INF=INT_MAX;

vector<Edge> graph[MAXN];
int inDegree[MAXN];
int earliest[MAXN];  // 最早开始时间
int latest[MAXN];  // 最晚开始时间 

void CriticalPath(int n){
	vector<int> topology;
	queue<int> node;
	for(int i=0;i<n;i++){
		if(inDegree[i]==0){
			node.push(i);
			earliest[i] = 1;
		}
	}
	// 求最早开始时间 
	while(!node.empty()){
		int u = node.front();
		node.pop();
		for(int i=0;i<graph[u].size();i++){
			int v = graph[u][i].to;
			int len = graph[u][i].length; 
			// 所有先序活动的最早开始时间+完成时间 = 该活动的最早开始时间
			earliest[v] = max(earliest[v],earliest[u]+len);
			inDegree[v]--;
			if(inDegree[v]==0){
				node.push(v);
			} 
		}
	}
	// 求最晚开始时间 
	for(int i=topology.size()-1;i>=0;i--){
		int u = topology[i];
		// 初始化最晚开始时间
		if(graph[u].size()==0){
			latest[u] = earliest[u];  // 汇点的最晚开始时间等于最早开始时间 
		} else{
			latest[u] = INF;
		}
		for(int j=0;j<graph[u].size();j++){
			int v = graph[u][j].to;
			int len = graph[u][j].length; 
			// 所有后序活动的最晚开始时间-完成时间 = 该活动的最晚开始时间
			latest[u] = min(latest[u],latest[v]-len);
		}
	}
	
}

int main(){
	int n,m;
	while(cin>>n>>m){
		memset(graph,0,sizeof(graph));
		memset(inDegree,0,sizeof(inDegree));
		for(int i=0;i<m;i++){
			int from,to,len;
			cin>> from>>to>>len;
			graph[from].push_back(Edge(to,len));
			inDegree[to]++; 
		}
		CriticalPath(n);
		int ans=0;
		for(int i=0;i<n;i++){
			ans = max(ans,earliest[i]);  // 用安全距离表示活动，且最早开始时间初始化为1，代表着完成时间，则汇点的最早开始时间即为关键路径长度 
		}
		cout<<ans<<endl;
	}
	return 0;
}
