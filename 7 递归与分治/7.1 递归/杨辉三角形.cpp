#include<iostream>

using namespace std;

const int MAXN=100;

int main(){
    int n;
    int arr[MAXN][MAXN];
    arr[0][0]=1;
    arr[1][0]=1;
    arr[1][1]=1;
    for(int i=2;i<MAXN;i++){
        for(int j=1;j<i;j++){
            arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
        }
        arr[i][0]=1;
        arr[i][i]=1;
    }
    while(cin>>n){
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}