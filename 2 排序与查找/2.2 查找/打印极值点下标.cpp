#include<iostream>

using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int left,curr,right;
        for(int i=0;i<n;i++){
            cin>>right;
            if(i==0){
                left = curr = right;
                continue;
            }
            if(i==1 && curr != right){  // 判断第一个数 
                printf("%d ",i-1);
            }else if((left < curr && right < curr) || (left > curr && right > curr)){
                printf("%d ",i-1);
            }
            left = curr;
            curr = right;
        }
        if(left != curr) printf("%d ",n-1);  // 判断最后一个数
        printf("\n"); 
    }
    return 0;
}
