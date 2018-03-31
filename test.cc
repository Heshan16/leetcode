#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        recur_partition(s,res,temp,0);
        return res;
    }
    
    void recur_partition(string &s,vector<vector<string>> &res,vector<string> &temp,int starti) {
        int sz=s.size();
        if(starti==sz)
            res.push_back(temp);
        for(int j=starti;j<sz;j++){
            if(palindrome(s,starti,j)) {
                temp.push_back(s.substr(starti,j-starti+1));
                recur_partition(s,res,temp,j+1);
                temp.pop_back();
            }
        } 
    }
    
    bool palindrome(string &s,int beg,int end) {
		static int i=0;
		i++;
		cout<<i<<' ';
        while(beg<end && s[beg]==s[end])
            beg++,end--;
        return beg>=end;
    }
};



int main() {
	Solution s1;
	string s("aaaaaaaaaa");
	s1.partition(s);
	return 0;
}
