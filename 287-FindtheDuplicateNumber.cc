//solution 1,O(n) time
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int fast=nums[nums[0]];
        int slow=nums[0];
        
        while(slow!=fast) {
            fast=nums[nums[fast]];
            slow=nums[slow];
        }
        slow=0;
        while(slow!=fast) {
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
};

//Solution 2,O(nlogn) time
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low=1,high=nums.size()-1;
        while(low<high) {
            int middle=(low+high)/2;
            int cnt=0;
            for(auto i:nums) {
                if(i<=middle)
                    cnt++;
            }
            if(cnt<=middle)
                low=middle+1;
            else
                high=middle;
        }
        return low;
    }
};
