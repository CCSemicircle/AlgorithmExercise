class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> chars(128,0);  // 某个字符缺少数量
        vector<bool> flag(128,false);  // 字符是否在T中
        // cnt是指当前覆盖T中字符的个数
        int cnt = 0, l = 0, min_l = 0, min_size = s.size()+1;  // min_size的设置是考虑当s全部计入可以覆盖的情况
        // 初始化
        for(int i=0;i<t.size();++i){
            flag[t[i]]=true;
            ++chars[t[i]];
        }
        for(int r=0;r<s.size();++r){
            if(flag[s[r]]){
                if(--chars[s[r]]>=0){
                    // 如果去除当前的字符不再大于零，代表已经全覆盖当前字符
                    ++cnt;
                }
                // 如果当前已经实现全覆盖，判断是否更新子串
                // 同时，尝试向右移动l，如果刚好r到达的字符是l的字符，即可顺利移动
                while(cnt == t.size()){
                    if(r-l+1 < min_size){
                        min_l = l;
                        min_size = r-l+1;
                    }
                    // 如果l是t中字符，则移动l后需要更新cnt
                    if(flag[s[l]] && ++chars[s[l]] > 0){
                        --cnt;
                    }
                    ++l;
                }
            }
        }
        return min_size > s.size() ? "" : s.substr(min_l,min_size);
    }
};