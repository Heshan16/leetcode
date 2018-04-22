class Solution {
public:
    int numTrees(int n) {
        if(n<=0)
            return 0;
        vector<int> numVec(n+1);
        numVec[0]=1;
        for(int i=1;i<=n;i++) {
            int t=0,v=0,p=i-1;
            while(v<p) 
                t+=numVec[v++]*numVec[p--]*2;
            if(v==p)
                t+=numVec[v]*numVec[p];
            numVec[i]=t;
        }
        return numVec[n];
    }
};
