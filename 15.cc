class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        bool repeate=false;
        int size=nums.size();
        for(int i=0;i<size;i++)
            for(int j=i+1;j<size;j++)
                for(int k=j+1;k<size;k++)
                    if(!(nums[i]+nums[j]+nums[k])){
                        set<int> temp={nums[i],nums[j],nums[k]};
                        for(auto vec:result) {
                            set<int> reset(vec.begin(),vec.end());
                            if(reset==temp) {
                                repeate=true;
                                break;
                            }
                         }
                        if(!repeate)
                            result.push_back({nums[i],nums[j],nums[k]});
                        repeate=false;
                    }
        return result;
    }
};
