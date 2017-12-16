class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        std::sort(nums.begin(),nums.end());
        int i=0,sz=nums.size();
        for(i=0;i<sz-2;i++) {
            int find=nums[i]*(-1);
            int j=i+1,end=sz-1;
            while(j<end) {
                if(nums[j]+nums[end]>find)
                    end--;
                else if(nums[j]+nums[end]<find)
                    j++;
                else {
                    vector<int> temp{nums[i],nums[j],nums[end]};
                    result.push_back(std::move(temp));
					//为避免重复三元组
                    while(j+1<sz && nums[j+1]==nums[j])
                        j++;
                    j++;
                }
            }
			//避免重复三元组
            while(i+1<sz && nums[i+1]==nums[i])
                i++;
        }
        return result;
    }
};
