#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct Station{
    double price;
    double distance;
};

bool StationCompare(Station x,Station y){
    return x.distance < y.distance;
}

const int MAXN=501;

Station station[MAXN];

int main(){
    double Cmax,D,Davg;
    int N;
    while(cin>>Cmax>>D>>Davg>>N){
        for(int i=0;i<N;i++){
            cin>>station[i].price>>station[i].distance;
        }
        // 将最终的重点视为price为0的station
        station[N].price=0.0;
        station[N].distance=D;
        sort(station,station+N,StationCompare);
        double maxRun = Cmax * Davg, cost = 0.0, nowGas=0.0,addGas=0.0,needGas=0.0;
        if(station[0].distance != 0){
            // 起始站distance不为0，无法出发
            printf("The maximum travel distance = 0.00\n");
            continue;
        }
        bool flag = true; // 是否可以到达终点
        int i=0;
        while(i<N){
            int k=0;
            // 找到所有可达站
            while(i+k <= N && station[i+k].distance - station[i].distance <= maxRun){
                k++;
            }
            // 去掉最后不符合的station
            k--;
            if(k<=0){
                // 没有可达的下一站
                printf("The maximum travel distance = %.2f\n", station[i].distance + maxRun);
                flag=false;
                break;
            }
            int j;
            for(j=i;j<=i+k;j++){
                if(station[j].price < station[i].price) break;
            }
            if(j <= i+k){
                // 1. 在可达范围内找到了比当前站价格更低的，则加油到刚好到达下一站
                needGas=(station[j].distance - station[i].distance)/Davg;
                if(nowGas >= needGas) nowGas -= needGas;  // 判断当前油量是否充足，并计算到达下一站的花费
                else{
                    addGas = needGas - nowGas;
                    nowGas = 0.0;  // 计算到达下一站的花费
                    cost += addGas * station[i].price;
                }
            }else{
                // 2. 可达范围内没有找到价格更低的，找可达范围内价格最低的（虽然高于当前站）
                j = i+1;  // 注意与上面的区别，此处为i+1
                for(int temp=j+1;temp<=i+k;temp++){
                    if(station[temp].price < station[j].price) j=temp;
                }
                needGas = (station[j].distance - station[i].distance)/Davg;
                // 因为下一站价格更高，因而当前站需要加满
                addGas = Cmax - nowGas;
                nowGas = Cmax - needGas;   // 计算到达下一站的花费
                cost += addGas * station[i].price;
            }
            // 调整当前站的位置
            i = j;
        }
        if(flag){
            printf("%.2f\n",cost);
        }
    }     
    return 0;
}