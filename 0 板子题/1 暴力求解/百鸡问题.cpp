#include<iostream>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        for(int x=0;x<=100;x++){
            // 注意y的边界值
            for(int y=0;y<=100-x;y++){
                int z=100-x-y;
                // 注意次数的判断方式
                if(15*x+9*y+z <= 3*n){
                    printf("x=%d,y=%d,z=%d\n",x,y,z);
                }
            }
        }
    }
    return 0;
}