/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front. 
*/
//此题其实算法十分简单，直接×，+即可，关键在于此题要细心处理各种情况，比如前面有空格，比如前面有+-符号，然后小心处理digit字符背后的非digit字符。
int myAtoi(string str) {
        bool if_positive=true;
        int i=0;
        bool overflow=false;
        while(str[i]==' ' || str[i]=='\t')
            i++;
        if(str[i]=='+'){
            i++;
        }
        else if(str[i]=='-') {
            i++;
            if_positive=false;
        }
        
        long long number = 0;
        int size=str.size();
        for(;i<size;i++) {
            if(!isdigit(str[i]))
                break;
            number*=10;
            number+=(str[i]-'0');
            if(number>INT_MAX){
                //overflow
                if(if_positive)
                    return INT_MAX;
                return INT_MIN;
            }
        }
	if(!if_positive)
            number*=-1;
        return (int)number;
}
