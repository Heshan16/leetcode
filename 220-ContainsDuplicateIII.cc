class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int sz=nums.size();
        set<int> occur;
        if(t<0)
            return false;
        for(int i=0;i<sz;i++) {
            if(i>k)
                occur.erase(nums[i-k-1]);
            if(occur.find(nums[i])!=occur.end()) 
                   return true;
            auto it=occur.insert(nums[i]).first;
            auto bef=it,aft=it;
            if((bef!=occur.begin()) && abs(*(--bef)-(long long)nums[i])<=t)
                return true;
            if((++aft!=occur.end()) && abs(*aft-(long long)nums[i])<=t)
                return true;   
        }
        return false;
    }
};

//Solution 2
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> window; // set is ordered automatically 
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) window.erase(nums[i-k-1]); // keep the set contains nums i j at most k
            // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
            auto pos = window.lower_bound((long long)nums[i] - t); 
            //v>=u-t,so next step should make v<=u+t
            if (pos != window.end() && (long long)*pos - (long long)nums[i] <= t) return true;
            window.insert(nums[i]);
        }
        return false;
    }
};
