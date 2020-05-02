class Solution {
public:
    bool isAnagram(string s, string t) {
        int a1[27] = {0,}, a2[27] = {0,};
        for(int i = 0;i<s.length();i++) a1[s[i]-'a']++;
        for(int i = 0;i<t.length();i++) a2[t[i]-'a']++;
        for(int i = 0;i<27;i++) if(a1[i]!=a2[i]) return false;
        return true;
    }
};