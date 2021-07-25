#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN=11;

int main(){
    int n;
    while(cin>>n){
        vector<string> path[MAXN];  // vector���飬��ά����
        for(int i=0;i<n;i++){
            string str;
            cin>>str;
            // ���ַ������ΪĿ¼�б�
            string temp;
            for(int j=0;j<str.length();j++){
                if(str[j] != '\\'){
                    temp += str[j];
                }else{
                    path[i].push_back(temp);
                    temp.clear();  // һ��Ҫע�����
                }
            }
        }
        // ����
        sort(path,path+n);
        for(int i=0;i<n;i++){
            int index=0;
            string space;
            // Ѱ������һ����ͬ��Ŀ¼�ṹ��ȷ��ÿ����·����ʼ�Ŀո���space
            while(i>0 && index < path[i-1].size() && index < path[i].size() && path[i-1][index] == path[i][index]){
                index++;
                space += "  ";
            }
            // ���
            for(;index < path[i].size(); index++, space += "  "){
                cout<<space<<path[i][index]<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
