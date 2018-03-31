class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> coincount(amount+1,-1);
        std::sort(coins.begin(),coins.end());
        coincount[0]=0;
        int sz=coins.size();
        for(int i=1;i<=amount;i++) {
            for(int j=0;j<sz && i-coins[j]>=0;j++) {
                if(coincount[i-coins[j]]>=0 && (coincount[i]==-1 || coincount[i-coins[j]]+1<coincount[i]))
                    coincount[i]=coincount[i-coins[j]]+1;
            }
        }
        return coincount[amount];
    }
};



