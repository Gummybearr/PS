class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int mval = 0, mcnt = 0;
        for(int i:nums){
            auto it = m.find(i);
            if(it==m.end()){
                m.insert({i,1});
                if(1>mcnt){
                    mcnt = 1;
                    mval = i;
                }
            }
            else{
                it->second++;
                if(it->second>mcnt){
                    mcnt = it->second;
                    mval = i;
                }
            }
        }
        return mval;
    }
};