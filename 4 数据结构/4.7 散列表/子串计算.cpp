#include<iostream>
#include<map>
#include<iostream>

using namespace std;

int main(){
    map<string,int> m;
    string str;
    while(getline(cin,str)){
        int len = str.size();
        // i代表子串长度，j代表子串起始下标
        for(int i=1;i<=len;i++){
            for(int j=0;j<=len-i;j++){
                string temp = str.substr(j,i);
                m[temp]++;
            }
        }
        // map内部有序，无需再排序
        for(auto it = m.begin();it!=m.end();it++){
            if(it->second > 1){
                cout<<it->first<<" "<<it->second<<endl;
            }
        }
    }
    return 0;
}