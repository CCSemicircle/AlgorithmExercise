// 方法一：逐步递推
/*
#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n,k;
    while(cin>>n){
        priority_queue<int,vector<int>, greater<int> > Q;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            Q.push(x);
        }
        cin>>k;
       // 处理第一个数
        int curr=Q.top();
        int last=Q.top();
        k--;
        Q.pop();
        while(k && !Q.empty()){
            curr = Q.top();
            if(curr != last){
                // 如果当前数不等于上一个数，排名递推k--，否则变
                k--;
                last = curr;
            }
            Q.pop();
        }
        cout<<curr<<endl;
    }
    return 0;
}
*/

// 方法二：利用set+vector
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
 
int main(){
    int n,a[1010];
    while(cin>>n){
        vector<int> vec;
        for(int i=0;i<n;i++)cin>>a[i];
        vec.assign(a,a+n);
        set<int > mySet(vec.begin(),vec.end());
        vec.assign(mySet.begin(),mySet.end());
        sort(vec.begin(),vec.end());
        cin>>n;
        cout<<vec[n-1]<<endl;
    }
    return 0;
}