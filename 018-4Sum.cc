class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        std::sort(nums.begin(),nums.end());
        int sz=nums.size();
        for(int firs=0;firs+3<sz;firs++) {
            int find=target-nums[firs];
	//剪枝优化
            if(nums[firs+1]+nums[firs+2]+nums[firs+3]>find)
                break;
            else if(nums[sz-1]+nums[sz-2]+nums[sz-3]<find)
                continue;
            for(int sec=firs+1;sec+2<sz;sec++) {
                int find2=find-nums[sec];
                int third=sec+1,forth=sz-1;
		//剪枝优化
                if(nums[third]+nums[third+1]>find2)
                    break;
                else if(nums[forth]+nums[forth-1]<find2)
                    continue;
                while(third<forth) {
                    if(nums[third]+nums[forth]>find2)
                        forth--;
                    else if(nums[third]+nums[forth]<find2)
                        third++;
                    else {
                        vector<int> temp{nums[firs],nums[sec],nums[third],nums[forth]};
                        result.push_back(std::move(temp));
                        while(third+1<sz && nums[third]==nums[third+1])
                            third++;
                        third++; //important,if will fall in infinite loop without this
                    }
                }
                while(sec+1<sz && nums[sec+1]==nums[sec])
                    sec++;
            }
            while(firs+1<sz && nums[firs+1]==nums[firs])
                firs++;
        }
        return result;
    }
};
