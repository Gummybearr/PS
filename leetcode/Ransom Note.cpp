class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cache[27] = {0,};
        for(int i = 0;i<magazine.length();i++){
            cache[magazine[i]-'a']++;
        }
        for(int i = 0;i<ransomNote.length();i++){
            cache[ransomNote[i]-'a']--;
            if(cache[ransomNote[i]-'a']<0) return false;
        }
        return true;
    }
};