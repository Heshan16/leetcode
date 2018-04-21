class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> vi(n,1);
        int i2=0,i3=0,i5=0;
        for(int i=1;i<n;i++) {
            while(vi[i2]*2<=vi[i-1])
                i2++;
            while(vi[i3]*3<=vi[i-1])
                i3++;
            while(vi[i5]*5<=vi[i-1])
                i5++;
            int t2=vi[i2]*2,t3=vi[i3]*3,t5=vi[i5]*5;
            vi[i]=min(vi[i2]*2,min(vi[i3]*3,vi[i5]*5));
        }
        return vi[n-1];
    }
};
