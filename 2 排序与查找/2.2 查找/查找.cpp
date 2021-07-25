#include<iostream>
#include<algorithm>

using namespace std;


// 注意此处需要使用const
const int MAXN=100;

int a[MAXN];

bool search(int x,int n){
    int left=0;
    int right=n-1;
    while(left<=right){
//         int mid=(left+right)/2;
        // 避免left+right 生成超大整数溢出
        int mid=(left)+(right-left)/2;
        if(a[mid]==x)
            return true;
        // 注意left 和 right的更新应该排除原有mid，否则当最后只剩两个时，可能无法得出结果，陷入死循环
        else if(a[mid]>x){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return false;
}

// 尽量避免递归
// bool search(int x,int left,int right){
//     if(left>right) return false;
//     int mid=(left+right)/2;
//     if(a[mid]==x) return true;
//     else if(a[mid]>x) return search(x,left,mid-1);
//     else return search(x,mid+1,right);
// }

int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>a[i];
        int m;
        cin>>m;
        int b[m];
        for(int i=0;i<m;i++)
            cin>>b[i];
        sort(a,a+n);
        for(int i=0;i<m;i++){
            if(search(b[i], n))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
       
    }
    return 0;
}
