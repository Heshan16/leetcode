#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
  	int maxsquare(const vector<int> &row) {
		int sz=row.size();
		vector<int> fromleft(sz,1);
		vector<int> fromright(sz,1);
		for(int i=0;i<sz;i++) {
			if(row[i]<=0)
				continue;
			int j=i-1;
			while(j>=0 && row[j]>=row[i]) { 
				fromleft[i]+=fromleft[j];
				j-=fromleft[j];
			}
		}
		for(int i:fromleft)
			cout<<i<<' ';
		cout<<endl;
		for(int i=sz-1;i>=0;i--) {
			int j=i+1;
			if(row[i]<=0)
				continue;
			while(j<sz && row[j]>=row[i]){
				fromright[i]+=fromright[j];
				j+=fromright[j];
			}
		}
		for(int j:fromright)
			cout<<j<<' ';
		cout<<endl;
		int maxcur=0;
		for(int i=0;i<sz;i++) {
			int mint=min(fromleft[i]+fromright[i]-1,row[i]);
			maxcur=max(maxcur,mint);
		}
		return maxcur;
	}
};



int main() {
	Solution s1;
	int sz;
	cout<<s1.maxsquare(vector<int>{3,3,1,3});
	cin>>sz;
	vector<int> vi(sz);
	while(1) {
	for(int i=0;i<sz;i++)
		cin>>vi[i];
	cout<<s1.maxsquare(vi)<<endl;
	}
	return 0;
}
