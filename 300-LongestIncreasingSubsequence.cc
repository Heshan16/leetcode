//O(n^2) solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> length(nums.size(),1);
        int sz=nums.size();
        for(int i=1;i<sz;i++) {
            int max=0;
            for(int j=0;j<i;j++)
                if(nums[i]>nums[j] && length[j]>max)
                    max=length[j];
            length[i]=max+1;
        }
        int max=0;
        for(int i=0;i<sz;i++)
            if(length[i]>max)
                max=length[i];
        return max;
    }
};


//O(nlogn) solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int sz=nums.size(),curi=0;
        vector<int> end_num(sz);
        end_num[0]=nums[0];
        for(int i=1;i<sz;i++) {
            if(nums[i]>end_num[curi])
                end_num[++curi]=nums[i];
            else {
                int start=0,end=curi;
                while(start<end) {
                    int mid=start+(end-start)/2;
                    if(end_num[mid]>=nums[i])
                        end=mid;
                    else
                        start=mid+1;
                }
                end_num[end]=nums[i];
            }
        }
        return curi+1;
    }
};
