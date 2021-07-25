#include<iostream>
using namespace std;
int main(){
    string f1,f2;
    while(getline(cin,f1)){
        getline(cin,f2);
        int pos1=f1.find('.');
        int pos2=f2.find('.');
        // 整数部分补0 
        if(pos1>pos2){
            f2.insert(0,pos1-pos2,'0');
        }else{
            f1.insert(0,pos2-pos1,'0');
        }
        // 小数部分补0 
        if(f1.length()>f2.length()){
            f2.insert(f2.length(),f1.length()-f2.length(),'0');
        } else{
            f1.insert(f1.length(),f2.length()-f1.length(),'0');
        } 
        int carry=0;  // 进位 
        for(int i=f1.length()-1;i>=0;--i){
            if(f1[i]=='.')  continue;
            f1[i]+=f2[i]-'0'+carry;
            carry=(f1[i]-'0')/10;
            f1[i]=(f1[i]-'0')%10+'0';
        }
        cout<<f1<<endl;
    } 
    return 0;
}
