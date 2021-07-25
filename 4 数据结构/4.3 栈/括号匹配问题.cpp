#include<iostream>
#include<stack>

using namespace std;

int main(){
	string str;
	while(getline(cin,str)){
		stack<char> bracket;
		string ans(str.size(),' '); // 初始默认为空格 
		for(int i=0;i<str.size();i++){
			if(str[i]=='('){
				bracket.push(i);
			}else if(str[i] == ')'){
				if(!bracket.empty()){
					// 因为压入栈的全为左括号，所以可以直接出栈
					bracket.pop();
				}else{
					ans[i]='?';
				}
			}
		}
		while(!bracket.empty()){
			ans[bracket.top()]='$';
			bracket.pop();
		}
		cout<<ans<<endl;
	}
	return 0;
} 
