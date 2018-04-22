class Solution {
public:
    int guessNumber(int n) {
        int beg=1,end=n;
        while(beg<=end) {
            int mid=beg+(end-beg)/2;
            int t=guess(mid);
            if(t==-1)
                end=mid-1;
            else if(t==0)
                return mid;
            else
                beg=mid+1;
        }
        return -1;
    }
};
