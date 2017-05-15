//既然是无序表，可以考虑使用hash表的方法，以时间换空间，即以（数，下标）的形式将数存于hash表中，
//对每个数依次检查，若是在hash表中找到其目标值，则找到最终结果，并返回之。
//否则则将其存于hash表中，便于后来数检索
//本算法时间复杂度O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash1;
        vector<int> result;
        int number_of_found;
        
        int len=nums.size();
        for(int i=0;i<len;i++) {
            int curr=nums[i];
            number_of_found=target-curr;
            
            if(hash1.find(number_of_found)!=hash1.end()){
               result.push_back(hash1[number_of_found]);
               result.push_back(i);
               return result;
            }
            else 
                hash1[curr]=i;
        }
        return result;
    }
};
