class Solution {
public:
    int rob(vector<int>& nums) {
        int sz=nums.size();
        if(sz<2)
            return (sz==0)?0:nums[0];
        vector<int> getting(sz);
        for(int i=0;i<2;i++)
            getting[i]=nums[i];
        if(sz>2)
            getting[2]=nums[0]+nums[2];
        for(int i=3;i<sz;i++)
            getting[i]=max(getting[i-2],getting[i-3])+nums[i];
        return max(getting[sz-1],getting[sz-2]);
    }
};

//more simple solution
class Solution {
public:
    int rob(vector<int>& nums) {
        int ppre=0,pre=0;
        for(auto i:nums){
            int cur=max(ppre+i,pre);
            ppre=pre;
            pre=cur;
        }
        return pre;
    }
};
