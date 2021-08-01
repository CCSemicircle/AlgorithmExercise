#include<iostream>
#include<queue>
#include<climits>
#include<vector>
#include<cstring>

using namespace std;

struct Edge{
    int to;
    int length;
    Edge(int t, int l):to(t),length(l){}
};

struct Point{
    int number;
    int distance;
    Point(int n,int d):number(n),distance(d){}
    bool operator<(const Point& p) const {
        return distance > p.distance;
    }
};


const int MAXN=610;
const int INF=INT_MAX;

vector<Edge> graph[MAXN];
int dis[MAXN];
int leader[MAXN];   // 对应城市的leader

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
            // 只能有一次从1到2，意味着不存在从2到1
            if(!(leader[u] == 2 && leader[v] == 1) && (dis[u] + len < dis[v])){
                dis[v] = dis[u]+len;
                Q.push(Point(v,dis[v]));
            }
        }
    }
}

int main(){
    int n,m;
    while(cin>>n>>m && n){
        memset(graph,0,sizeof(graph));
        // 此处同样注意起始编号的问题
        fill(dis,dis+n+1,INF);
        
        for(int i=0;i<m;i++){
            int from,to,length;
            cin>>from>>to>>length;
            // 无向边
            graph[from].push_back(Edge(to,length));
            graph[to].push_back(Edge(from,length));
        }
        for(int i=1;i<=n;i++){
            cin>>leader[i];
        }
        Dijkstra(1);
        if(dis[2] == INF){
            dis[2] = -1;
        }
        cout<<dis[2]<<endl;
    }
    return 0;
}