#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN=201;
const int INF = INT_MAX;

struct Edge{
	int to;
	int length;
	Edge(int t, int l):to(t),length(l){}
}; 

struct Point{
	int number;  // 顶点编号 
	int distance;  // 到源点s的距离 
	Point(int n,int d):number(n),distance(d){}
	// 一定要加const 
	bool operator<(const Point& p) const {
		return distance > p.distance;  // 距离小的优先级高，（在优先队列里面，默认小的放后面） 
	}
};

vector<Edge> graph[MAXN];
int dis[MAXN];


void Dijkstra(int s){
	priority_queue<Point> Q;
	dis[s] = 0;
	Q.push(Point(s,dis[s]));
	while(!Q.empty()){
		int u = Q.top().number;
		Q.pop();
		for(int i=0;i<graph[u].size();i++){
			int v = graph[u][i].to;
			int len = graph[u][i].length;
			if(dis[u]+len < dis[v]){
				dis[v] = dis[u]+len;
				// 只有有更新才重新加入优先队列 
				Q.push(Point(v,dis[v]));
			}
		}
	}
}

int main(){
	int n,m;
	while(cin>>n>>m){
		// 注意初始化 
		memset(graph,0,sizeof(graph));
		fill(dis,dis+n,INF);
		
		for(int i=0;i<m;i++){
			int from,to,length;
			cin>>from>>to>>length;
			graph[from].push_back(Edge(to,length));
		}
		int s,t;
		cin>>s>>t;
		Dijkstra(s);
		if(dis[t] == INF){
			dis[t] = -1;
		}
		cout<<dis[t]<<endl;
	}
	return 0;
}
