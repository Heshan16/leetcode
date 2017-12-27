/*
 Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(),nums.end());
        vector<int> vec;
        recur_subset(vec,res,nums,0);
        return res;
    }
    void recur_subset(vector<int> &vec,vector<vector<int>> &res,vector<int> &nums,int beg){
        res.push_back(vec);
        for(int i=beg;i<nums.size();i++)
            if(i==beg || nums[i]!=nums[i-1]) {
                vec.push_back(nums[i]);
                recur_subset(vec,res,nums,i+1);
                vec.pop_back();
            }
    } 
};

/* Sulition 2

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res{{}};
        //res.push_back(vector<int>());
        std::sort(nums.begin(),nums.end());
        int sz=nums.size();
        for(int i=0;i<sz;i++) {
            int count=1;
            while(i+count<sz && nums[i]==nums[i+count])
                count++;
            i+=count-1;
            int presz=res.size();
            for(int j=0;j<presz;j++) {
                vector<int> temp=res[j];
                for(int k=0;k<count;k++){
                    temp.push_back(nums[i]);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};

*/
