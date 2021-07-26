#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

const int MAXN=100001;

struct Status{
    int n,t;
    Status(int n,int t):n(n),t(t){}
};


bool visit[MAXN];   // 记录状态是否被访问（入栈）

int BFS(int n,int k){
    queue<Status> Q;
    // 压入初始状态
    Q.push(Status(n,0));  // 注意初始t=0
    visit[n]=true;
    while(!Q.empty()){
        Status current = Q.front();
        Q.pop(); 
        if(current.n == k){
            return current.t;
        }
        // 访问一个状态后，访问其下一层的所有合法状态
        for(int i=0;i<3;i++){
            Status next(current.n,current.t+1);
            if(i == 0){
                next.n +=1;
            }else if(i == 1){
                next.n -=1;
            }else{
                next.n *=2;
            }
            if(next.n < 0 || next.n >= MAXN || visit[next.n]){
                continue;
            }
            // 压入（访问）合法状态
            Q.push(next);
            visit[next.n] = true;
        }
    }
}

int main(){
    int n,k;
    while(cin>>n>>k){
        memset(visit,false,sizeof(visit));  // 初始化visit数组
        cout<<BFS(n,k)<<endl;
    }
}
