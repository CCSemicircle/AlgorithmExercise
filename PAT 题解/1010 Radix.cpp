#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int CharToInt(char ch){
    if('0' <= ch && ch <= '9'){
        return ch-'0';
    }else{
        return ch-'a'+10;
    }
}

unsigned long long Transfer(string num,int radix){
    unsigned long long decimal = 0;
    int len = num.size();
    // 从字符串到数字，正序遍历，逐步乘与加
    // 从数字到字符串，反序遍历，逐步模与除
    for(int i=0;i < len ;i++){
        decimal = decimal*radix + CharToInt(num[i]);
    }
    return decimal;
}

int GetMinRadix(string num){
    // 所有字符中最大的数字(包括字母)
    char ch = 0;
    for(int i=0;i<num.size();i++){
        if(num[i] > ch){
            ch = num[i];
        }
    }
    return CharToInt(ch)+1;  // 要比最大元素大1
}

int main(){
    string n1,n2;
    int tag,radix;
    cin>>n1>>n2>>tag>>radix;
    // 始终将已知基数的数设置为n1
    if(tag == 2){
        swap(n1,n2);  // string头文件自带函数
    }
    // 将数字n1转为十进制数字
    unsigned long long num1 = Transfer(n1,radix);
    
    // 将n2按照不同进制转换为数字与n1比较，采用二分查找减少遍历
    unsigned long long minRadix = max(GetMinRadix(n2),1);  // 最小进制为n2字符串中最大的数字(包括字母)
    
    // 每位最大为35，但是不代表最大进制是36
    // 最大进制是假设除最高位非0其他位均为0时的取值（因为是进制与每一位的权值相乘再相加，和值一定时，为保证进制越大，权值要尽量小或项数尽量少），即num1取len次幂，注意使用1.0转为浮点数
    // 此处的len表示最高位权值的指数项
    int len = max((int)n2.size()-1, 1);  // 如果减1后为0，需要设置为1，注意max的大小比较类型需要一致，此处需要强制类型转换
    unsigned long long maxRadix = pow(num1,1.0/len)+1;
    while(minRadix <= maxRadix){
        int middle = (maxRadix+minRadix)/2;
        unsigned long long num2 = Transfer(n2,middle);
        if(num1 == num2){
            cout<<middle<<endl;
            break;
        }else if(num1 < num2){
            maxRadix = middle-1;
        }else{
            minRadix = middle+1;
        }
    }
    if(minRadix > maxRadix){
        cout<<"Impossible"<<endl;
    }
    return 0;
}