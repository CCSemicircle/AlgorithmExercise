#include<iostream>

using namespace std;

struct Country{
    float gold;
    float award;
    float civil;
    float gold_civil;
    float award_civil;
};

int main(){
    int n,m;
    while(cin>>n>>m){
        Country cous[n];
        // 国家是否参与排名的标记
        bool order[n]; 
        for(int i=0;i<n;i++){
            cin>>cous[i].gold>>cous[i].award>>cous[i].civil;
            // 考虑人口为0的情况
            if(cous[i].civil==0) cous[i].civil = 1e-5;
            cous[i].gold_civil=cous[i].gold/cous[i].civil;
            cous[i].award_civil=cous[i].award/cous[i].civil;
        }
        
        for(int i=0;i<m;i++){
            int temp=0;
            cin>>temp;
            order[temp]=true;
        }
        
        for(int i=0;i<n;i++){
            
            // 此处不能用!order[i]，因为只要Order[i]不为0，!order[i]就为假
            if(order[i]!=true){
//                 cout<<order[i]<<endl;
                continue;
            }
                
            
            int gold_order=1;
            int award_order=1;
            int gold_civil_order=1;
            int award_civil_order=1;
            
            for(int j=0;j<n;j++){
                // 更新排名，解决并列
                if(cous[i].gold < cous[j].gold)
                    gold_order++;
                if(cous[i].award < cous[j].award)
                    award_order++;
                if(cous[i].gold_civil < cous[j].gold_civil)
                    gold_civil_order++;
                if(cous[i].award_civil < cous[j].award_civil)
                    award_civil_order++;
            }
            
            // 如果人口为0，但是金牌或者奖牌数不为0，理应比例都为第一名，注意上面设置了非0操作，此处不要直接与0比较
            if(cous[i].civil<1){
                if(cous[i].gold!=0) gold_civil_order=1;
                if(cous[i].award!=0) award_civil_order=1;
            }
            
            // 查找四种排名里最小排名，并输出
            if(gold_order <=  award_order){
                if(gold_order <= gold_civil_order){
                    if(gold_order <= award_civil_order){
                        cout<<gold_order<<":1"<<endl;
                    }else{
                        cout<<award_civil_order<<":2"<<endl;
                    }
                }
                else if(gold_civil_order <= award_civil_order){
                    cout<<gold_civil_order<<":3"<<endl;
                }
                else{
                    cout<<award_civil_order<<":4"<<endl;
                }
            }
            else if(award_order <= gold_civil_order){
                if(award_order <= award_civil_order){
                    cout<<award_order<<":2"<<endl;
                }
                else{
                    cout<<award_civil_order<<":4"<<endl;
                }
            }
            else if(gold_civil_order <= award_civil_order){
                cout<<gold_civil_order<<":3"<<endl;
            }
            else{
                cout<<award_civil_order<<":"<<4<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
