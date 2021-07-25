/**高精度整数——大整数的因子**/
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

const int MAXN = 10000;

struct BigInteger{
	int digit[MAXN];
	int length;
	BigInteger();
	BigInteger(int x);
	BigInteger(string str);
	BigInteger(const BigInteger& b);
	BigInteger operator=(int x);
	BigInteger operator=(string str);
	BigInteger operator=(const BigInteger& b);
	bool operator<=(const BigInteger& b);
	bool operator==(const BigInteger& b);
	BigInteger operator+(const BigInteger& b);
	BigInteger operator-(const BigInteger& b); 
	BigInteger operator*(const BigInteger& b); 
	BigInteger operator/(const BigInteger& b); 
	BigInteger operator%(const BigInteger& b);
	friend istream& operator>>(istream& in, BigInteger& x);
	friend ostream& operator<<(ostream& out, const BigInteger& x);
};

istream& operator>>(istream& in,BigInteger& x){
	string str;
	in>>str;
	x = str;
	return in;
}

ostream& operator<<(ostream& out,const BigInteger& x){
	for(int i=x.length-1;i>=0;i--)
		out<<x.digit[i];
	return out;
}

BigInteger::BigInteger(){
	memset(digit,0,sizeof(digit));
	length=0;
}

BigInteger::BigInteger(int x){
	memset(digit,0,sizeof(digit));
	length=0;
	if(x==0)
		digit[length++] = x;
	while(x !=0 ){
		digit[length++] = x%10;
		 x/=10;
	} 
}

BigInteger::BigInteger(string str){
	memset(digit,0,sizeof(digit));
	length=str.size();
	for(int i=0;i<length;i++){
		digit[i]=str[length-1-i]-'0';
	} 
}

BigInteger::BigInteger(const BigInteger& b){
	memset(digit,0,sizeof(digit));
	length=b.length;
	for(int i=0;i<length;i++){
		digit[i]=b.digit[i];
	}
}

BigInteger BigInteger::operator=(int x){
	memset(digit,0,sizeof(digit));
	length=0;
	if(x==0){
		digit[length++]=x;
	}
	while(x!=0){
		digit[length++]=x%10;
		x/=10;
	}
	return *this;
} 

BigInteger BigInteger::operator=(string str){
	memset(digit,0,sizeof(digit));
	length=str.size();
	for(int i=0;i<length;i++){
		digit[i]=str[length-1-i]-'0';
	}
	return *this;
}

BigInteger BigInteger::operator=(const BigInteger& b){
	memset(digit,0,sizeof(digit));
	length=b.length;
	for(int i=0;i<length;i++){
		digit[i]=b.digit[i];
	}
	return *this;
}

bool BigInteger::operator<=(const BigInteger& b){
	if(length < b.length){
		return true;
	}else if(b.length < length){
		return false;
	}else{
		for(int i=length-1;i>=0;i--){
			if(digit[i]==b.digit[i]){
				continue;
			}else{
				return digit[i]<b.digit[i];
			}
		}
	}
	return true;
}

bool BigInteger::operator==(const BigInteger& b){
	if(length != b.length){
		return false;
	}else{
		for(int i=length-1;i>=0;i--){
			if(digit[i]!=b.digit[i]){
				return false;
			}
		}
	}
	return true;
}

BigInteger BigInteger::operator+(const BigInteger& b){
	BigInteger answer;
	int carry=0;
	for(int i=0;i<length || i<b.length;i++){
		int current=carry+digit[i]+b.digit[i];
		carry = current/10;
		answer.digit[answer.length++]=current%10;
	}
	if(carry!=0){
		answer.digit[answer.length++]=carry;
	}
	return answer;
}

BigInteger BigInteger::operator-(const BigInteger& b){
	BigInteger answer;
	int carry=0; // 借位 
	for(int i=0;i<length;i++){
		int current = digit[i]-b.digit[i]-carry;
		if(current <0){
			current +=10;
			carry =1;
		}else{
			carry=0;
		}
		answer.digit[answer.length++]=current;
	}
	while(answer.digit[answer.length-1]==0 && answer.length>1){
		answer.length--;
	}
	return answer;
}

BigInteger BigInteger::operator*(const BigInteger& b){
	BigInteger answer;
	answer.length = length + b.length;
	// 竖式乘法运算 
	for(int i=0;i<length;i++){
		for(int j=0;j<b.length;j++){
			// 注意每个结果存放的位置，以及当前不一定是一位数 
			answer.digit[i+j] += digit[i]*b.digit[j];
		}
	}
	for(int i=0;i<answer.length;i++){
		answer.digit[i+1] += answer.digit[i]/10;
		answer.digit[i]%=10;
	}
	while(answer.digit[answer.length-1]==0 && answer.length>1){
		answer.length--;
	}
	return answer;
}

BigInteger BigInteger::operator/(const BigInteger& b){
	BigInteger answer;
	answer.length =length;
	BigInteger remainder =0;
	BigInteger temp=b;
	for(int i=length-1;i>=0;i--){
		// 当前值（剩余值）整体往前进一位 
		if(!(remainder.length==1 && remainder.digit[0]==0)){
			for(int j=remainder.length-1;j>=0;j--){
				remainder.digit[j+1] = remainder.digit[j];
			}
			remainder.length++;
		}
		remainder.digit[0]=digit[i];
		// 从右至左（从小到大）遍历，当前值（剩余值）比temp大时，用累减计数来计算此处的商 
		while(temp <= remainder){
			remainder = remainder -temp;
			answer.digit[i]++;
		}	
	}
	while(answer.digit[answer.length-1]==0 && answer.length>1){
		answer.length--;
	}
	return answer;
} 

BigInteger BigInteger::operator%(const BigInteger& b){
	BigInteger remainder=0;
	BigInteger temp=b;
	// 与除法一致，只是最后的值返回的是当前值（剩余值） 
	for(int i=length-1;i>=0;i--){
		if(!(remainder.length==1 && remainder.digit[0]==0)){
			for(int j=remainder.length-1;j>=0;j--){
				remainder.digit[j+1] = remainder.digit[j];
			}
			remainder.length++;
		}
		remainder.digit[0]=digit[i];
		while(temp <= remainder){
			remainder = remainder -temp;
		}	
	}
	return remainder;
}

int main(){
    string str;
    while(cin>>str && str != "-1"){
        BigInteger c(str);
        bool first =true;
        for(int i=2;i<=9;i++){
            if(c % BigInteger(i) == 0){
                if(first){
                    cout<<i;
                    first =false;
                }
                else
                    cout<<" "<<i;
            }
        }
        if(first)
            cout<<"none";
        cout<<endl;
    }
    return 0;
}