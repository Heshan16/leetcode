class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> occur;
        int sz=nums.size(),t=min(sz,k+1);
        for(int i=0;i<t;i++) {
            if(occur.find(nums[i])!=occur.end())
                return true;
            occur.insert(nums[i]);
        }
        for(int i=t;i<sz;i++){
            occur.erase(nums[i-t]);
            if(occur.find(nums[i])!=occur.end())
                return true;
            occur.insert(nums[i]);
        }
        return false;
    }
};
