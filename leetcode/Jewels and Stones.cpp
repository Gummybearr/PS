class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int jewel[500]={0,};
        int cnt = 0;
        for(int i = 0;i<J.length();i++) jewel[(int)J[i]]++;
        for(int i = 0;i<S.length();i++) if(jewel[S[i]]>0) cnt++;
        return cnt;
    }
};