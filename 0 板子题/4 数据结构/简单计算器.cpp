#include<iostream>
#include<stack>
#include<string>

using namespace std;

int GetPriority(char ch){
    // '#'代表运算符栈最低级，'$'代表运算符次低级，放在字符串最后
    if(ch == '#' ){
        return 0;
    }else if(ch == '$'){
        return 1;
    }
    else if(ch == '+' || ch=='-'){
        return 2;
    }else if(ch == '*' || ch=='/'){
        return 3;
    }
}

double Compute(double a, double b, char ch){
    if(ch=='+'){
        return a+b;
    }else if(ch == '-'){
        return a-b;
    }else if(ch == '*'){
        return a*b;
    }else if(ch == '/'){
        return a/b;
    }
}

double GetNumber(int& index, string str){
    double ans=0.0;
    while(str[index] >= '0' && str[index] <= '9'){
        ans *= 10;
        ans += str[index]-'0';
        index++;
    }
    return ans;
}

int main(){
    string str;
    while(getline(cin,str)){
        if(str == "0"){
            break;
        }
        stack<double> number;
        stack<char> oper;
        oper.push('#');
        str += '$';  // 最后添加特殊字符，判断结束,很重要
        int i=0;
        while(oper.top()!='$'){
            if(str[i] == ' '){
                i++;
                continue;
            }
            else if(str[i]>= '0' && str[i] <= '9'){
                number.push(GetNumber(i, str));
            }
            else{
                if(GetPriority(str[i]) <= GetPriority(oper.top())){
                    // 小于或等于栈顶的优先级，先计算栈顶的运算符
                    // 注意取出数字的顺序
                    double b = number.top();
                    number.pop();
                    double a = number.top();
                    number.pop();
                    double ch = oper.top();
                    oper.pop();
                    double temp = Compute(a,b,ch);
                    number.push(temp);
                }else{
                    // 大于栈顶的优先级，直接入栈
                    oper.push(str[i]);
                    i++;
                }
            }
        }
        double ans = number.top();
        printf("%.2f\n",ans);
    }
    return 0;
}
