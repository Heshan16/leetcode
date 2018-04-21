//O(nlogn) time
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int end=citations.size(),beg=0,sz=end;
        while(beg<end) {
            int mid=beg+(end-beg)/2;
            if(citations[mid]>=sz-mid)
                end=mid;
            else
                beg=mid+1;
        }
        return sz-end;
    }
};
