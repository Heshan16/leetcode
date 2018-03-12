/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem. 
*/

//Solution 1
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz=nums.size();
        vector<int> res(sz);
        k=k%sz;
        for(int i=0;i<sz;i++)
            res[i]=nums[(i-k+sz)%sz];
        nums=std::move(res);
    }
};

//Solution 2
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
//Solution 3
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int cursz=nums.size(),i=0,j=0;
        while(k%=cursz){
            for(j=0;j<k;j++) 
                swap(nums[i+j],nums[i+(j-k+cursz)]);
            i+=k;
            cursz-=k;
        }
    }
};

//Solution 4
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int beg=0,rcnt=0,sz=nums.size();
        while(rcnt<sz) {
            int cur=nums[beg],start=beg;
            do {
                beg=(beg+k)%sz;
                swap(nums[beg],cur);
                rcnt++;
            } while(beg!=start);
            beg++;
        }
    }
};
