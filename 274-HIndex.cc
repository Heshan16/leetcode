//O(nlogn) solution
class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(),citations.end(),[](int a,int b) {return a>b;});
        int i=0,sz=citations.size();
        while(i<sz && citations[i]>=i+1)
            i++;
        return i;
    }
};

//Solution 2,O(n) time,O(logn) space
public:
    int hIndex(vector<int>& citations) {
        int beg=0,end=citations.size()-1;
        while(beg<end) {
            int order=partition(citations,beg,end);
            if(citations[order]>=order+1)
                beg=order;
            else
                end=order-1;
        }
        return ((!citations.empty()) && (citations[beg]>=beg+1))?beg+1:0;
    }
    int partition(vector<int> &citations,int beg,int end) {
        if(beg==end)
            return beg;
        swap(citations[beg],citations[end]);
        int i=beg,j=end,pivot=citations[beg];
        while(i<j) {
            while(i<j && citations[j]<pivot)
                j--;
            citations[i]=citations[j];
            while(i<j && citations[i]>=pivot)
                i++;
            citations[j]=citations[i];
        }
        citations[i]=pivot;
        return i;
    }
};

//O(n) time ,o(N) space
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())
            return 0;
        vector<int> num(citations.size()+1);
        int sz=citations.size(),quan=0,i=0;
        
        for(auto i:citations) 
            (i>=sz)?num[sz]++:num[i]++;
        
        for(i=sz;i>=0 && i>quan;i--) {
            quan+=num[i];
            if(quan>=i) //notice there ,can't write it in for condition directly
                return i;
        }
        return i;
    }
};

