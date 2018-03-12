class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.size()+num2.size(),'0');
        for(int i=num1.size()-1;i>=0;i--) {
            int carry=0;
            for(int j=num2.size()-1;j>=0;j--) {
                int temp=(res[i+j+1]-'0')+(num1[i]-'0')*(num2[j]-'0')+carry;
                carry=temp/10;
                res[i+j+1]=temp%10+'0';
            }
            res[i]=carry+'0';
        }
        auto pos=res.find_first_not_of('0');
        return (pos==string::npos)?"0":res.substr(pos);
    }
};
