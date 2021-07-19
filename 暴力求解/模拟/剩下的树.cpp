#include<iostream>

#define MAXN 100001

using namespace std;

bool trees[MAXN];

int main(){
    int l,m;
    // 注意可能有多组数据
    while(cin >> l>>m){
        int start,end;
        int number = l +1;
        for(int i=0;i<=l;i++)
            trees[i]=true;
        while(m--){
            cin>>start>>end;
            for(int i=start;i<=end;i++){
                if(trees[i]){
                    trees[i]=false;
                    number--;  // 同时计数，减少时间开销 
                }
            }
        }
        cout<<number<<endl;
    }

    return 0;
}
