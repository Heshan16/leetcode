//Solution 1,using Floyd cycle
class Solution {
public:
    bool isHappy(int n) {
        int t1=n;
        int t2=n;
        do {
            t1=squar_dig(squar_dig(t1));
            t2=squar_dig(t2);            
        } while(t1!=1 && t1!=t2);
        return t1==1;
    }
    
    int squar_dig(int n) {
        string s=to_string(n);
        int res=0;
        for(auto c:s) {
            res+=(c-'0')*(c-'0');
        }
        return res;
    }
};

//Solution 2,using hashset
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> occur;
        while(n!=1 && occur.find(n)==occur.end()){
            occur.insert(n);
            n=squar_dig(n);
        }
        return n==1;
    }
    
    inline int squar_dig(int n) {
        string s=to_string(n);
        int res=0;
        for(auto c:s) {
            res+=(c-'0')*(c-'0');
        }
        return res;
    }
};
