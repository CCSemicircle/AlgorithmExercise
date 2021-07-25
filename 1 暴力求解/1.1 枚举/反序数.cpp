#include<iostream>

int Reverse(int x){
    int ans=0;
    while(x){
        ans *=10;
        ans += x%10;
        x /= 10;
    }
    return ans;
}

int main(){
    for(int i=1000;i<10000;i++){
        if(Reverse(i) == i*9){
            printf("%d\n",i);
        }
    }
    return 0;
}