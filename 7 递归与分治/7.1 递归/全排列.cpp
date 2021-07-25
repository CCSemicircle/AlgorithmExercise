// 两种写法，思路基本相同

// 方法一
// 对于递归中的任何一种情况，分成已确定的前缀str.size() - len 与待排列的后缀len，
// 每次排列从后缀中任选一个字母加入前缀（共选len次）,然后len - 1
// 直到len == 1即为递归出口，此时前缀与后缀都确定，可以输出,输出顺序也为字典序。
#include<iostream>
#include<string>
#include<algorithm>
 
using namespace std;
 
void permutation(string str, int len){
    if(len==1) cout<<str<<endl;
    for(int i=0;i<len;i++){
        string temp(str);
        char head=temp[temp.size()-len+i];  // 每次从后缀中选一个字母
        temp.erase(temp.size()-len+i,1);  // 删掉head并加入到前缀的最后
        temp.insert(str.size()-len,1,head);
        permutation(temp,len-1);  // 递归调用
    }
}
 
int main(){
    string str;
    while(cin>>str){
        sort(str.begin(),str.end());  // 防止未排序好的初始字符串
        permutation(str,str.size());
        cout<<endl;
    }
    return 0;
}


// 方法二
// 分为前半段和后半段，前半段是已经确定的字符串，然后从后半段中遍历取每一个字符加到前半段的后面
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

const int MAXN=7;

void Function(string former, string later){
    if(later.size()==0){
        cout<<former<<endl;
    }else{
        for(int i=0;i<later.size();i++){
            Function(former+later[i], later.substr(0,i)+later.substr(i+1));
        }
    }
}

int main(){
    string str;
    while(getline(cin,str)){
        int n = str.size();
        sort(str.begin(),str.end());
        for(int i=0;i<str.size();i++){
            Function(str.substr(i,1), str.substr(0,i)+str.substr(i+1));
        }
    }
    return 0;
}