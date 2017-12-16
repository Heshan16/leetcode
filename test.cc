#include<iostream>
#include<algorithm>
#include<vector>
//#include<set>
#include<unordered_set>
using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
   //     unordered_set<int> ui;
        vector<vector<int>> result;
        if(candidates.empty())
            return result;
      //  vector<int> backup(candidates);
        sort(candidates.begin(),candidates.end());
        int i=1,j=1,sz=candidates.size(),last=candidates[0];
        for(;i<sz;i++) {
            if(candidates[i]!=last) {
                candidates[j++]=candidates[i];
                last=candidates[i];
            }
        }
        candidates.erase(candidates.begin()+j,candidates.end());
		for(auto in:candidates)
			cout<<in<<' ';
		cout<<endl;
//        vector<vector<int>> result;
        vector<int> cur_vec;
        combinationsum_recur(result,cur_vec,candidates,target,0,0);
        
        //candidates=move(backup);
        return result;
    }

    void combinationsum_recur(vector<vector<int>> &result,vector<int> &cur_vec,vector<int> &candidates,int target,int cur,int index) {
        if(cur==target)
            result.push_back(cur_vec);
        for(int i=index;i<candidates.size() && cur+candidates[i]<=target;i++) { //notice the check condition
            cur_vec.push_back(candidates[i]);
            combinationsum_recur(result,cur_vec,candidates,target,cur+candidates[i],i);
            cur_vec.pop_back();
        }
    }
};

int main() {
	Solution s1;
	vector<int> temp{10,1,2,7,6,1,5};
	for(auto in:temp)
		cout<<in<<' ';
	cout<<endl;
	auto res=s1.combinationSum2(temp,8);
	for(auto vi:res) {
		for(auto i:vi)
			cout<<i<<' ';
		cout<<endl;
	}
}
