bool cmp(pair<int, int> a, pair<int, int> b){
        return a.first<b.first;
    }

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> pdata;
        for(int i = 0;i<nums.size();i++){
            pdata.push_back({nums[i], i});
        }
        sort(pdata.begin(), pdata.end(), cmp);
        vector<int> v;
        int left = 0, right = nums.size()-1;
        while(left<right){
            int twosum = pdata[left].first+pdata[right].first;
            //printf("twosum : %d\n", twosum);
            if(twosum>target)   right--;
            else if (twosum<target) left++;
            else {
                v.push_back(pdata[left].second);
                v.push_back(pdata[right].second);
                break;
            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};