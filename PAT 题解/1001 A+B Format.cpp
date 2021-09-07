#include<iostream>
#include<string>

using namespace std;

int main(){
    long long a,b;
    while(cin>>a>>b){
        long long sum = a+b;
        if(sum < 0){
            cout<<"-";
            sum =-sum;
        }
        string str = to_string(sum);
        int len = str.size();
        for(int i=0;i<len;i++){
            if(i!=0 && (len - i)%3==0){
                cout<<",";
            }
            cout<<str[i];
        }
        cout<<endl;
    }
    return 0;
}