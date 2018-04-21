class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sz=nums.size();
        for(int i=0;i<sz;i++) {
            while(nums[i]<sz && nums[i]!=i)
                swap(nums[i],nums[nums[i]]);
        }
        for(int i=0;i<sz;i++)
            if(nums[i]==sz)
                return i;
        return sz;
    }
};

//异或的利用，惊为天人
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=nums.size();
        for(int i=0;i<nums.size();i++)
            res=res^i^nums[i];
        return res;
    }
};
