/*
首先，除了蚂蚁A之外，其余蚂蚁碰头交换速度等价于这两只蚂蚁按照原速度继续爬行。
将蚂蚁A想象为红点，其余蚂蚁为黑点，两个黑点相撞互换速度（实际上速度相同，互换的是方向），从视觉上来看，这两个黑点并没有改变状态，而是穿过彼此继续前行。
因此，只需要考虑黑点与红点相撞的情况即可。红点左边向左运动的点永远不会与红点相撞，同理右边向右运动的点亦然。
因此只需考虑红点左边向右运动的点数left和红点右边向左运动的点right数。
若left=right，则两边与红点交换的速度相互抵消，红点不会坠落。
若left>right，则红点将与第left-right个点交换速度并最终向右坠落，坠落时间是第left-right个点运动到100的时间。
若left<right，红点最终向左坠落，坠落时间是right与left抵消之后右边第一个right点运动到0的时间。
*/

#include<iostream>
#include<algorithm>

using namespace std;

int MAXN=100;

struct Ant{
    int pos;            //  蚂蚁位置
    int dir;            //  蚂蚁运动方向
    bool operator <(const Ant & a) const{
        return pos<a.pos;  // 按pos排序
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
            if(ants[i].dir==0) apos=ants[i].pos; // 记录蚂蚁A的位置
        }
        
        sort(ants,ants+n); // 排序
        
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
            // 遍历在A左边向右走的蚂蚁
            int k=0;
            for(int i=0;i<n;i++){
                if(ants[i].dir==1) k++;
                if(k==left_r-right_l){
                    cout<<100-ants[i].pos<<endl;
                    break; // 必须加停止，不然会一直输出
                }
            }
        }else{
            // 遍历在A右边向左走的蚂蚁
            int k=0;
            for(int i=n-1;i>=0;i--){
                if(ants[i].dir==-1) k++;
                if(k==right_l - left_r){
                    cout<<ants[i].pos<<endl;
                    break; // 必须加停止，不然会一直输出
                }
            }
        }
    }
    return 0;
}
