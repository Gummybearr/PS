class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int val = 0;
        for(int i:nums){
            val^=i;
        }
        return val;
    }
};