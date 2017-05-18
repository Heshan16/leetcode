/*Determine whether an integer is a palindrome. Do this without extra space.*/


//本来此题转换成字符串再一一检验，十分简单且直观，但题中已说不可多用空间。
//那么可考虑，用另一个数字表示其回文后的前半部分，显然对于回文数字，回文后的数字一定不可能大于原数字。
//注意，中间字符若仅有一个 则需回文乘之后，而原数未除10才两数相等。而两个中间字符的情况，则需两边均操作后才相等。故注意要在x未除10前再检查是否两数相等
    bool isPalindrome(int x) {
        if(x<0 || ((x!=0) && x%10==0))
            return false;
        int revernum=0;
        while(x>revernum){
            revernum*=10;
            revernum+=x%10;
            if(x==revernum)
                return true;
            x=x/10;
        }
        if(x==revernum)
            return true;
        return false;
    }
