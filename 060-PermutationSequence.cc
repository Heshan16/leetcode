/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> vi(n);
        for(int i=0;i<n;i++)
            vi[i]=i+1;
        string res;
        k--;
        int interval=1;
        for(int t=n;t>1;t--)
            interval*=t;
        while(n>0) {
            interval/=n;
            int seq=k/interval;
            k%=interval;
            res+=(vi[seq]+'0');
            vi.erase(vi.begin()+seq);
            n--;
        }
        return res;
    }
};
