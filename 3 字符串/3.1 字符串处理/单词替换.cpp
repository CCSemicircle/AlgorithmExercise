#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;


int main(){
    string sentence,init,replace;
    while(getline(cin,sentence)){
        getline(cin,init);
        getline(cin,replace);
        stringstream ss(sentence);
        string word;
        vector<string> words;
        while(getline(ss,word,' ')){
            words.push_back(word);
        }
        for(int i=0;i<words.size();i++){
            if(words[i]==init){
                words[i]=replace;
            }
        }
        // 注意此处的终止边界
        for(int i=0;i<words.size()-1;i++){
            cout<<words[i]<<" ";
        }
        cout<<words[words.size()-1]<<endl;
    }
    return 0;
}
