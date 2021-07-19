#include<cstdio>
#include<iostream>
#include<string>
#include<regex>

using namespace std;

string text[1001];

int main () {
    int n;
    scanf("%d", &n);
    cin.get();
    for (int i=1; i<=n; ++i)
        getline(cin, text[i]);
    getline(cin, text[0]);  // 把待匹配的字符存到0下标位置
    regex r(text[0], regex::icase);  // regex::icase 不区分大小写
    for (int i=1; i<=n; ++i)
        if (regex_match(text[i], r))  // 这是完全匹配，部分匹配用regex_search
            cout << i << ' ' << text[i] << endl;
    return 0;
}
