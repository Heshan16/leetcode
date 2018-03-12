/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer. */

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::sort(nums.begin(),nums.end(),
                 [](int num1,int num2)
                  {return to_string(num1)+to_string(num2)>to_string(num2)+to_string(num1);});
        string res;
        if(!nums.empty() && nums[0]==0)
            return "0";
        for(auto i:nums)
            res+=to_string(i);
        return res;
    }
};
