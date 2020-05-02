class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        string s;
        for(int i= 0;i<digits.size();i++)   s.push_back(digits[i]);
        for(int i= s.length()-1;i>=0;i--){
            if(s[i]==9) s[i] = 0;
            else{s[i]++; break;}
        }
        vector<int> ans;
        if(s[0]==0) ans.push_back(1);
        for(int i = 0;i<s.length();i++) ans.push_back(s[i]);
        return ans;
    }
};