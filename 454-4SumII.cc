class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int sz=A.size();
        int result=0;
        unordered_map<int,int> abnum;
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++) {
                int num=A[i]+B[j];
                    abnum[num]++;
            }
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++) {
                int num=C[i]+D[j];
                auto it=abnum.find(-num);
		//直接用second引用即可，不需再使用下标再次查找
                if(it!=abnum.end())
                    result+=it->second;
            }
        return result;
    }
};
