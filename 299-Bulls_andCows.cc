class Solution {
public:
    string getHint(string secret, string guess) {
        int sz=secret.size();
        vector<int>vi(10);
        int bull=0,cows=0;
        for(int i=0;i<sz;i++) {
            if(secret[i]==guess[i])
                bull++;
            else {
                if(vi[secret[i]-'0']++<0)
                    cows++;
                if(vi[guess[i]-'0']-->0)
                    cows++;
            }
        }
        return to_string(bull)+'A'+to_string(cows)+'B';
    }
};
