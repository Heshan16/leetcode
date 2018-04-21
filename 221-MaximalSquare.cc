//My solution,long
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
		int row=matrix.size(),col=matrix[0].size();
		vector<int> currow(col);
		int maxsq=0;
		for(int i=0;i<row;i++) {
			for(int j=0;j<col;j++)
				currow[j]=(matrix[i][j]=='1')?(currow[j]+1):0;
			maxsq=max(maxsq,maxsquare(currow));
		}
		return maxsq*maxsq;
    }
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
		for(int i=sz-1;i>=0;i--) {
			int j=i+1;
			if(row[i]<=0)
				continue;
			while(j<sz && row[j]>=row[i]){
				fromright[i]+=fromright[j];
				j+=fromright[j];
			}
		}
		int maxcur=0;
		for(int i=0;i<sz;i++) {
			int mint=min(fromleft[i]+fromright[i]-1,row[i]);
			maxcur=max(maxcur,mint);
		}
		return maxcur;
	}
};


//dp 
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
			return 0;
		int row=matrix.size(),col=matrix[0].size(),last=0,maxs=0;
		vector<int> currow(col+1);
		for(int i=0;i<row;i++)
			for(int j=1;j<=col;j++) {
				int temp=currow[j];
				if(matrix[i][j-1]=='1') {
					currow[j]=min(last,min(currow[j-1],currow[j]))+1;
                    maxs=max(currow[j],maxs);
				}
                else 
                    currow[j]=0;//it can't be omitted,because it may not 0,if it won't the first row
				last=temp;
			}
		return maxs*maxs;
    }
};
