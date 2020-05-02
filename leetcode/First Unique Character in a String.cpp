class Solution {
public:
    int firstUniqChar(string s) {
        int a[27] = {0,};
        for(int i = 0;i<s.length();i++) a[s[i]-'a']++;
        int ans = -1;
        for(int i = 0;i<s.length();i++)
            if(a[s[i]-'a']==1){ans = i;    break;}
        return ans;
    }
};