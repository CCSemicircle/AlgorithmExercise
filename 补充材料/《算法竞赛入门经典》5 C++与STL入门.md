---
title: 《算法竞赛入门经典》5 C++与STL入门
categories:
    - 算法刷题
    - 《算法竞赛入门经典》
tags:
    - 笔记
---

# 5 C++与STL入门

## 5.1 从C到C++

### 5.1.1 C++与C的不同

- C++能编译大多数C语言程序。虽然C语言中大多数头文件在C++中仍然可以使用，但推荐的方法是**在C头文件之前加一个小写的c字母，然后去掉.h后缀**。比如：

```c++
#include<math.h>
// 变为
#inlude<cmath>
```

- C++中可以使用流简化输入输出操作。标准输入输出流在头文件iostream中定义，存在于名称空间std中。如果使用了 using namespace std 语句，则可以直接使用**。需要注意cin和cout运行太慢，有时会出现超时（一般情况下不会）**。同时流也可以加速，调用如下语句即可：

```c++
ios::sync_with_stdio(false);
```

- **声明数组时，数组大小可以使用const声明的常数**（这在C99中不允许），在C++中这种写法更为推荐，而不是用#define。
- C++中**支持bool类型数据**，用true和false分别表示真和假。

### 5.1.2 &引用

- C++中的引用可以在一定程度上代替C中的指针，例如，可以用“传引用”的方式让函数内直接修改实参。

```c++
void swap2(int& a, int& b){
    int t=a;
    a = b;
    b = t;
}
```

<!-- more -->

### 5.1.3 string字符串

- C++在string头文件里定义了string类型，直接支持流式读写，string有很多函数和运算符，但速度有些慢。

#### 5.1.3.1 声明字符串并赋值

```c++
#include<iostream>

using namespace std ;

int main()
{
    char cs[] = "hello,world" ;         //声明并初始化一个C-串
    string str ;                        //声明一个string串
    str = "hello,world" ;               //对string串进行赋值
    cout<<str<<endl ;

    //使用string类型初始化另一个string类型
    string s1(str) ;        cout<<s1<<endl ;
    string s2(str, 2) ;     cout<<s2<<endl ;
    string s3(str, 2, 5) ;  cout<<s3<<endl ;

    //使用C 字符串初始化string类型串
    string s4(cs) ;         cout<<s4<<endl ;
    string s5(cs, 2) ;      cout<<s5<<endl ;
    string s6(cs, 2, 5) ;   cout<<s6<<endl ;

    return 0 ;
}
```

#### 5.3.1.2 字符串的输入输出

除了**>>**、**cin.get()**和**cin.getline()**对字符串进进行输入外, string头文件中还定义了**getline()**函数用于输入string字符串。

```c++
#include<iostream>

using namespace std ;

int main()
{
    // 终止符不会保存到输入的字符串中去
    string s;
    getline(cin, s) ;           //使用默认的'\n'作为终止符
    cout<<s<<endl ;

    getline(cin, s, '!') ;      //以'!'作为终止符
    cout<<s<<endl;

    return 0 ;
}
```

#### 5.3.1.3 基本使用方法

```c++
// = 复制
string s1 = "hello" ;
string s2 = s1 ;        //复制

// + 连接
string s1 = "hello" ;
string s2 = "world" ;
s1 += s2 ;                //连接

// < > == 比较
string s1 = "hello" ;
string s2 = "world" ;
if(s1 < s2)
    cout<<"s1 < s2" ;    //比较

// reverse 倒置，algorithm头文件中的函数
string s = "hello" ;
reverse(s.begin(), s.end()) ; // 倒置，注意s.begin()和s.end()的使用

// s.find 从前往后查找，s.rfind 从后往前查找 
string s = "hello" ;
cout<<s.find("ll") ;        // 返回子串第一次出现的位置，未找到返回string::npos

// s.replace 替换
string s = "hello" ;
s.replace(0, 2, "aaa") ;    //将字符串s中下标0-2部分字符串替换为"aaa"
```

#### 5.1.3.4 string的更多方法

- **获取字符串状态**

```c++
s.size();  // 返回字符串大小
s.length();  // 返回字符串长度
s.max_size();  // 返回字符串最大长度
s.clear();  // 清空字符串
s.empty();  // 判断字符串是否为空
```

- **修改字符串**

```c++
// s.append 追加字符串到s
string s="hello";
s.append("world");  // 将"world"追加到s中

// s.push_back 追加字符到字符串
string s="hello";
s.push_back('!');  // 将'!'追加到s中

// s.inster 插入
string s="hello";
s.insert(2,"www");  // 将字符串"www"插入到字符串s中，插入位置为2

// s.erase 从字符串中擦除一些字符
string s="hello";
s.erase(1,2);  // 1代表位置，2代表擦除长度，表示从下标为1处向后擦去2个字符

// s1.swap(s2) 与另一字符串交换内容
string s1 = "hello" ;
string s2 = "world" ;
s1.swap(s2) ;            //将s1与s2中的字符串进行交换，无其他参数
```

- 访问string元素

```c++
// 1. 数组下标，0到size()-1
str[i];

// 2. 迭代器
for(string::iterator it=str.begin();it!=str.end();it++){}
```

- 常用函数

```c++
find();  // 若函数找到相应的字符或字符串，则返回对应的下标，若找不到返回string::npos
substr();  // 返回子串
```

### 5.1.4 结构体

- C++中的结构体除了可以拥有成员变量（用a.x的方式访问）之外，还可以拥有成员函数（用a.add(1,2)的方式访问）。
- C++中的结构体可以有一个或多个构造函数，在声明变量时调用。
- C++中的函数（不只是构造函数），可以拥有默认值。
- C++结构体的成员函数中，this是指向**当前对象**的指针。

- 例子如下

```c++
#include<iostream>
using namespace std;

struct Point{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){} // 注意此处的简化赋值方式
};  // 注意此处的分号必须要

// 重构 + 运算
Point operator + (const Point& A,const Point & B){
    return Point(A.x+B.x,A.y+B.y);
}

// 重构 << 输出，固定写法
ostream& operator << (ostream& out,const Point& p){
    out<<"("<<p.x<<","<<p.y<<")";
    return out;
}

int main(){
    Point a,b(1，2);
    a.x=3;
    cout<<a+b<<endl;
    return 0;
}
```

### 5.1.5 模板

- 工程中应用很广，算法竞赛中很少使用，直接看例子

```c++
template<typename T>
struct Point{
    T x,y;
    Point(T x=0, T y=0):x(x),y(y){}
};
```

### 5.1.6 algorithm头文件

#### 5.1.6.1 **max(x,y),min(x,y),abs(x)**

- max(x,y)和min(x,y)分别返回x和y中的最大值和最小值，且**参数必须是两个**。
- abs(x) 返回x的绝对值。**x必须为整数，浮点型的绝对值要用math头文件下的fabs**。

#### 5.1.6.2 **swap(x,y)**

- swap(x,y)用来交换x和y的值

#### 5.1.6.3 **reverse(it,it2)**

reverse(it,it2) 可以将数组指针在[it,it2)之间的元素或容器的迭代器在[it,it2)范围内的元素进行反转。

#### 5.1.6.4 **sort(a,a+n,cmp)**

- 默认为递增排序，若要递减排序，需要增加比较函数，

```c++
bool cmp(int a,int b){
  return a>b;
}
sort(a,a+n,cmp);
```

- 结构体数组排序

```c++
struct node{
  int x,y;
}a[10];
bool cmp(node a,node b){
  return a.x>b.x; 
}
bool cmp(int x,int y){
  if(a.x!=b.x) return a.x>b.x;
  else return a.y<b.y;
}
```

- 容器排序，在STL标准容器中，只有vector/string/queue可以sort

```c++
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    vector<int> vi;
    vi.push_back(3);
    vi.push_back(1);
    vi.push_back(2);f
    sort(vi.begin(),vi.end(),cmp); // 注意参数为vi.begin(),vi.end()
    for(int i=0;i<3;i++){
        printf("%d ",vi[i]);
    }
    return 0;
}
```

#### 5.1.6.5 **fill(a,a+n,num)**

```c++
int a[10]={1,2,3,4,5};
fill(a,a+5,233);  // 全部赋值为233
```

#### 5.1.6.6 **next_permutation(a,a+n)**

next_permutation() 给出一个序列在全排列中的下一个序列。

```c++
 #include<stdio.h>
 #include<string>
 #include<algorithm>
 using namespace std;
 int main()
 {
     int a[10]={1,2,3};
     do{
         printf("%d %d %d\n",a[0],a[1],a[2]);
     }while(next_permutation(a,a+3)); // 一直循环获取序列
     return 0;
 }
```

#### 5.1.6.7 **lower_bound(first,last,val)  upper_bound(first,last,val)**

lower_bound(first,last,val) 用来**寻找在数组或容器的[first,last)范围内第一个值大于等于val元素的位置**，如果是数组，返回该位置的指针；若果是容器，返回该位置的迭代器；
upper_bound(first,last,val) 用来**寻找在数组或容器的[first,last)范围内第一个值大于val元素的位置**，如果是数组，返回该位置的指针；若果是容器，返回该位置的迭代器。

如果数组或容器中没有需要寻找的元素，则 lower_bound()和 upper_bound()均返回可以插入该元素的位置的指针或迭代器(即假设存在该元素时，该元素应当在的位置)。

```c++
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int a[10]={1,2,2,3,3,3,5,5,5,5};
    // 注意返回的是地址，不是数组的索引，需要减去数组a的首地址获得索引
    printf("%d,%d\n",lower_bound(a,a+10,3)-a,upper_bound(a,a+10,3)-a);
    return 0;
}
```

## 5.2 STL初步

### 5.2.0 迭代器 iterator 

- 类似于指针，示例如下

```c++
for(set<string>::iterator it=dict.begin();it!=dict.end();++it){
    cout<< *it <<endl;
}
```

### 5.2.1 排序与检索

- 见**alogorithm头文件**

### 5.2.2 不定长数组 vector

- vector头文件中的vector是一个不定长数组，具有如下函数：

```c++
vector<int> v;  // 声明一维不定长数组
vector<int> pile[maxn];  // 声明二维数组，第一维大小固定（不超过maxn），第二位大小不固定
v.clear();  // 清空
v.resize(n);  // 改变大小
v.push_back(num);  // 在尾部添加元素
v.pop_back();  // 在尾部删除元素
v.empty;  // 判断是否为空
```

- vector之间可以之间赋值或者作为函数的返回值，类似int，float等类型。

### 5.2.3 集合 set

- set是数学上的集合，每个元素最多只出现一次。
- 与sort一样，自定义类型也可以构造set，但同样必须定义“小于”运算符。
- set中元素已从小到大排好序。

- 常用方法如下：

```c++
int a[]={1,2,3};
set<int> s(a,a+3); // 声明，可以关联数组，也可以不关联，直接用set<int> s声明
s.begin();  // 返回第一个元素的迭代器
s.end();  // 返回最后一个元素的下一个位置的迭代器
s.clear();  // 删除所有元素
s.empty();  // 判断set是否为空
s.max_size();  // 返回set的最大长度
s.size();  // 返回当前元素个数
s.insert(item);  // 插入元素
s.find(item);  // 返回给定值的
s.count(item);  // 返回某个元素出现的次数
s.erase(3);  // 删除指定元素，并返
```

### 5.2.4 映射 map

- map中元素已从小到大排好序。
- map提供了[]运算符，可以使得map可以像数组一样使用，例如可以用month_name["July"]=7这样的方式来赋值
- 常用方法如下：

```c++
// 构造map
map<int, string> m;  
// 赋值
m.insert(pair< int,string > (1,"Jim"));
m.insert(value_type (2, "Tom"));
mapPerson[3] = "Jerry";  // 常用
// 其他方法
m.begin();  // 返回指向 map 头部的迭代器
m.clear();  // 删除所有元素
m.count();  // 返回指定元素出现的次数
m.empty();  // 如果 map 为空则返回 true
m.end();  // 返回指向 map 末尾的迭代器
m.erase();  // 删除一个元素
m.find();  // 查找一个元素
m.key_comp();  // 返回比较元素key的函数
m.lower_bound();  // 返回键值>=给定元素的第一个位置
m.max_size();  // 返回可以容纳的最大元素个数
m.size();  // 返回map中元素的个数
m.swap();  // 交换两个map
m.upper_bound();  // 返回键值>给定元素的第一个位置
m.equal_range(item);  // 返回与item相等元素的迭代器区间A，返回数据格式为auto，用mit.first和mit.second获取区间的前后迭代器位置
// map内已排序，因而相等元素必定相邻，且由此可知 lower_bound返回区间A的第一个迭代器，算法upper_bound返回区间A的最后一个元素的下一个位置，算法equal_range则是以pair的形式将两者都返回。
// 取值
m[n];  // 取值方法1，没有关键字n时，使用[]取值会导致插入
m.at(n);  // 取值方法2，有关键字检查，会报错
it->first; it->second;  // 利用迭代器iterator取值
```

### 5.2.5 栈、队列与优先队列

#### 5.2.5.1 栈 stack

- stack头文件提供了栈，可以用 stack\<int\>  s定义，用push()和pop()实现元素的入栈和出栈操作，top()取栈顶元素（但不删除）。

#### 5.2.5.2 队列 queue

- queue头文件提供了队列，可以用 queue\<int\>  q 方式定义，用push()和pop()实现元素的入队和出队操作，front()取栈顶元素（但不删除）。

#### 5.2.5.3 优先队列 priority_queue

- 类似队列，但先出队列的元素不是先进队列的元素，而是队列中优先级最高的元素。
- queue头文件提供了优先队列，用 priority_queue\<int\>  pq定义，用push()和pop()实现元素的入队和出对操作，top()取栈顶元素（但不删除）。

- 还可以类似sort自定义小于运算，用 priority_queue\<int, vector\<int\>, cmp\> \>pq定义，注意最后两个 > 不要写在一起，否则会被很多编译器误认为是 >> 。

### 5.2.6 测试STL

#### 5.2.6.1 生成随机数

- **cstdlib中的rand()**可生成闭区间 [0, RANG_MAX]内均匀分布的随机整数，其中RANG_MAX至少为32767。
- 如果要生成更大的随机整数，在精度要求不太高的情况下可以用rand()的结果“放大”得到，同理，如果要生成较小范围内[0, n]的整数，可以先除以RAND_MAX，得到[0,1]之间的随机实数，扩大n倍后四舍五入得到。

#### 5.2.6.2 随机数种子

- cstdlib 中的 srand 函数初始化随机数种子。如果需要程序每次执行时使用一个不同的种子，可以用 ctime 中 time(NULL)为参数调用 srand，srand(time(NULL))。一般来说，旨在程序执行的开头调用一次 srand 。

#### 5.2.6.3 vector传参

- 把vector作为参数或者返回值时，应尽量改成用引用方式传递参数，以避免不必要（函数中未使用）的值被复制。

```c++
void fill_random_int(vector<int>& v, int cnt){
    v.clear();
    for(int i=0;i<cnt;i++){
        v.push_back(rand());
    }
}
```

#### 5.2.6.4 assert错误提示

- 测试时往往使用assert，其用法是 assert(表达式)，当表达式为假时，强行终止程序，并给出错误提示。t