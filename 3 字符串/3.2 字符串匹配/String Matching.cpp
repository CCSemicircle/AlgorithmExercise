#include<iostream>
#include<string>

using namespace std;

const int MAXN=1e6;

int nextTable[MAXN];


void GetNextTable(string pattern){
    int m = pattern.size();
    int j=0;
    nextTable[j]=-1;
    int i=nextTable[0];
    while(j < m){
        if(i == -1 || pattern[i] == pattern[j]){
            i++;
            j++;
            nextTable[j]=i;
        }
        else{
            i = nextTable[0];
        }
    }
}

int KMP(string text,string pattern){
    int n=text.size();
    int m = pattern.size();
    GetNextTable(pattern);
    int i=0;  // i索引text
    int j=0;  // j索引pattern
    int cnt=0;  
    while(i < n ){
        if(j == -1 || text[i] == pattern[j]){
            i++;
            j++;
            if(j == m){
                cnt++;
            }
        }else{
            j = nextTable[j];
        }
    }
    return cnt;
}


int main(){
    string text,pattern;
    while(cin>>text>>pattern){
        cout <<KMP(text,pattern)<<endl;
    }
    return 0;
}
