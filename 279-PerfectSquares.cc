class Solution {
public:
    int numSquares(int n) {
        vector<int> vi(n+1,0),t;
        for(int i=1;i*i<=n;i++) {
            vi[i*i]=1;
            t.push_back(i*i);
        }
        int tsz=t.size();
        for(int i=2;i<=n;i++) {
            int min=INT_MAX;
            if(vi[i]==1)
                continue;
            for(int j=0;j<tsz && t[j]<i;j++)
                if(vi[i-t[j]]<min)
                    min=vi[i-t[j]];
            vi[i]=min+1;
        }
        return vi[n];
    }
};
