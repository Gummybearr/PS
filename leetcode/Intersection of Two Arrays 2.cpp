class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        vector<int> ans;
        for(int i= 0;i<nums1.size();i++){
            auto it = m.find(nums1[i]);
            if(it==m.end()) m.insert({nums1[i], 1});
            else    it->second++;
        }
        for(int i = 0;i<nums2.size();i++){
            auto it = m.find(nums2[i]);
            if(it==m.end()) continue;
            else {
                it->second--;
                ans.push_back(it->first);
                if(it->second==0) m.erase(it->first);
            }
        }
        return ans;
    }
};