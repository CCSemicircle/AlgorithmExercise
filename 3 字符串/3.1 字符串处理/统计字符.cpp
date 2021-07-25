#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int cnt[128];

int main(){
    string str1,str2;
    while(getline(cin,str1)){
        memset(cnt,0,sizeof(cnt));
        if(str1=="#"){
            break;
        }
        getline(cin,str2);
        int bound2=str2.size();
        for(int i=0;i<str2.size();i++){
            cnt[str2[i]]++;
        }
        int bound1=str1.size();
        for(int i=0;i<bound1;i++){
            printf("%c %d\n",str1[i],cnt[str1[i]]);
        }
    }
    return 0;
}
