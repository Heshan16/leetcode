//Solution 1
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> occur;
        for(auto i:nums) {
            if(occur.find(i)!=occur.end())
                return true;
            occur.insert(i);
        }
        return false;
    }
};

//Solution 2
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return unordered_set<int>{nums.begin(),nums.end()}.size()!=nums.size();
    }
};
