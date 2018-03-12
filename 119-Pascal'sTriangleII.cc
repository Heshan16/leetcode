/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1]. 
Could you optimize your algorithm to use only O(k) extra space? 
*/

//Solution 1,o(n2) time
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,1);
        for(int i=2;i<=rowIndex;i++)
            for(int j=i-1;j>0;j--)
                res[j]=res[j-1]+res[j];
        return res;
    }
};

//Solution 2,o(n) time
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,1);
        int half=rowIndex/2,temp=1;
        for(int i=1;i<=half;i++) {
            temp=(long long)temp*(rowIndex+1-i)/i;
            res[i]=res[rowIndex-i]=temp;
        }
        return res;
    }
};

