/*
���ȣ���������A֮�⣬����������ͷ�����ٶȵȼ�������ֻ���ϰ���ԭ�ٶȼ������С�
������A����Ϊ��㣬��������Ϊ�ڵ㣬�����ڵ���ײ�����ٶȣ�ʵ�����ٶ���ͬ���������Ƿ��򣩣����Ӿ����������������ڵ㲢û�иı�״̬�����Ǵ����˴˼���ǰ�С�
��ˣ�ֻ��Ҫ���Ǻڵ�������ײ��������ɡ������������˶��ĵ���Զ����������ײ��ͬ���ұ������˶��ĵ���Ȼ��
���ֻ�迼�Ǻ����������˶��ĵ���left�ͺ���ұ������˶��ĵ�right����
��left=right�����������㽻�����ٶ��໥��������㲻��׹�䡣
��left>right�����㽫���left-right���㽻���ٶȲ���������׹�䣬׹��ʱ���ǵ�left-right�����˶���100��ʱ�䡣
��left<right�������������׹�䣬׹��ʱ����right��left����֮���ұߵ�һ��right���˶���0��ʱ�䡣
*/

#include<iostream>
#include<algorithm>

using namespace std;

int MAXN=100;

struct Ant{
    int pos;            //  ����λ��
    int dir;            //  �����˶�����
    bool operator <(const Ant & a) const{
        return pos<a.pos;  // ��pos����
    }
};

int main(){
    int n;
    while(cin>>n && n){
        Ant ants[n];
        int left_r=0,right_l=0;
        int apos;
        for(int i=0;i<n;i++){
            cin>>ants[i].pos>>ants[i].dir;
            if(ants[i].dir==0) apos=ants[i].pos; // ��¼����A��λ��
        }
        
        sort(ants,ants+n); // ����
        
        for(int i=0;i<n;i++){
            if(ants[i].pos < apos && ants[i].dir == 1)
                left_r++;
            if(ants[i].pos > apos && ants[i].dir == -1)
                right_l++;
        }
        
        if(left_r == right_l){
            cout<<"Cannot fall!"<<endl;
            continue;
        }
        if(left_r > right_l){
            // ������A��������ߵ�����
            int k=0;
            for(int i=0;i<n;i++){
                if(ants[i].dir==1) k++;
                if(k==left_r-right_l){
                    cout<<100-ants[i].pos<<endl;
                    break; // �����ֹͣ����Ȼ��һֱ���
                }
            }
        }else{
            // ������A�ұ������ߵ�����
            int k=0;
            for(int i=n-1;i>=0;i--){
                if(ants[i].dir==-1) k++;
                if(k==right_l - left_r){
                    cout<<ants[i].pos<<endl;
                    break; // �����ֹͣ����Ȼ��һֱ���
                }
            }
        }
    }
    return 0;
}
