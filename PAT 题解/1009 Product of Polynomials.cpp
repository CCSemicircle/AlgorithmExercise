#include<iostream>
#include<map>

using namespace std;

int main(){
    int k1,k2;
    map<int,double> A,B;
    cin>>k1;
    for(int i=0;i<k1;i++){
        int n;
        double a;
        cin>>n>>a;
        A[n] = a;
    }
    cin>>k2;
    for(int i=0;i<k2;i++){
        int n;
        double a;
        cin>>n>>a;
        B[n] = a;
    }
    map<int, double> ans;
    for(auto itA = A.begin();itA != A.end();itA++){
        for(auto itB = B.begin();itB != B.end();itB++){
            ans[itA->first+itB->first] += itA->second * itB->second;
        }
    }
    // 一定要去除系数为0的项
    for(auto it = ans.begin();it!=ans.end();it++){
        if(it->second == 0.0){
            ans.erase(it);
        }
    }
    printf("%d",ans.size());
    auto it = ans.end();
    for(it--;it!= ans.begin();it--){
        printf(" %d %.1f",it->first,it->second);
    }
    printf(" %d %.1f\n",it->first,it->second);
    return 0;
}