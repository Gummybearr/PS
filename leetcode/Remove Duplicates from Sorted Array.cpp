class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(int i = 0;i<nums.size();i++){s.insert(nums[i]);}
        vector<int> v;
        for(auto i:s){v.push_back(i);}
        nums = v;
        return s.size();
    }
};