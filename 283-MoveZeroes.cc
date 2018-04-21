class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0,sz=nums.size();
        for(;i<sz;i++) 
            if(nums[i])
                nums[j++]=nums[i];
        while(j<sz)
            nums[j++]=0;
    }
};
