#include<iostream>
#include<map>

using namespace std;

const int MAXN=1010;

int main(){
    int k1,k2;
    double num[MAXN]={0.0};
    int m;
    double a;
    cin>>k1;
    for(int i=0;i<k1;i++){
        cin>>m>>a;
        num[m] += a;
    }
    cin>>k2;
    for(int i=0;i<k2;i++){
        cin>>m>>a;
        num[m] += a;
    }
    int cnt=0;
    for(int i=0;i<MAXN;i++){
        if(num[i] !=0.0){
            cnt++;
        }
    }
    printf("%d",cnt);
    for(int i=MAXN-1;i>=0;i--){
        if(num[i] != 0.0){
           printf(" %d %.1f",i,num[i]);
        }
    }
    printf("\n");
    return 0;
}