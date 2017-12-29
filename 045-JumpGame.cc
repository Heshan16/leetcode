class Solution {
public:
    int jump(vector<int>& nums) {
        int start=0,count=0,end=0;
        int sz=nums.size();
        while(end<sz-1) {
            count++;
            int max=end;
            for(int i=start;i<=end;i++){
                if(i+nums[i]>=sz-1)
                    return count;
                else if(i+nums[i]>max)
                    max=i+nums[i];
            }
            start=end+1;
            end=max;
        }
        return count;
    }
};
