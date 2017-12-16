class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());
        int diff=INT_MAX,c_target=0;
        int sz=nums.size();
        for(int i=0;i<sz-2;i++) {
            int j=i+1,end=sz-1;
            int find=target-nums[i];
            while(j<end) {
                int sum=nums[j]+nums[end];
                int currdiff=sum-find;
                int plus_diff=(currdiff<0)?(-currdiff):currdiff;
                if(plus_diff<diff) {
                    diff=plus_diff;
                    c_target=sum+nums[i];
                }
                if(currdiff==0)
                    return target; //找到一样的数，无需再继续寻找
                else if(currdiff<0)
                    j++;
                else 
                    end--;
            }
        }
        return c_target;
    }
};
