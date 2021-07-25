#include<iostream>

#define MAXN 100001

using namespace std;

bool trees[MAXN];

int main(){
    int l,m;
    // ע������ж�������
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
                    number--;  // ͬʱ����������ʱ�俪�� 
                }
            }
        }
        cout<<number<<endl;
    }

    return 0;
}
