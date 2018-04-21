class Solution {
public:
    int calculate(string s) {
        stringstream ss;
        ss<<s;
        int opr1,opr2,opr3;
        char op1,op2;
        ss>>opr1;
        if(!(ss>>op1>>opr2))
            return opr1;
        while(ss>>op2>>opr3) {
            if((op2=='*' || op2=='/') && (op1=='+' || op1=='-')) 
                opr2=cal(opr2,opr3,op2);
            else {
                opr1=cal(opr1,opr2,op1);
                op1=op2;
                opr2=opr3;
            }
        }
        return cal(opr1,opr2,op1);
    }
    int cal(int n1,int n2,char op) {
        switch(op) {
            case '*'：
                return n1*n2;
            case '/':
                return n1/n2;
            case '+':
                return n1+n2;
        }
        return n1-n2;
    }
};
