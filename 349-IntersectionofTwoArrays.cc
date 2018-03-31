//O(m+n) time,o(min(m,n)) space
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            swap(nums1,nums2);
        vector<int> res;
        unordered_set<int> occur(nums1.begin(),nums1.end());
        for(auto i:nums2) {
            if(occur.find(i)!=occur.end()) {
                res.push_back(i);
                occur.erase(i);
            }
        }
        return res;
    }
};
