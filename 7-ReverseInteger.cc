//此题较简单，直接一一求余，将结果*10即可 
int reverse(int x) {
        //should initialize it
        long long result=0;
        while(x){
            result=result*10+x%10;
            x/=10;
        }
        if(result>INT_MAX || result<INT_MIN)
            return 0;
        return (int)result;
}
