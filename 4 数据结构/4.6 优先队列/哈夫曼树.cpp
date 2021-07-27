#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        int ans=0;
        // 默认是大顶堆，应该用下面的定义，定义小顶堆
        priority_queue<int, vector<int>, greater<int> > Q;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            Q.push(x);
        }
        while(1 < Q.size()){
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop();
            ans += a+b;
            Q.push(a+b);
        }
        cout<<ans<<endl;
    }
    return 0;
}