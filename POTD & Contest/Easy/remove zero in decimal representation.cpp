class Solution {
public:
    long long removeZeros(long long n) {
        long long ans = 0, position = 1;//akkok -1, dosok-2, sotok-3
        while(n >0){
            long long digit = n % 10;
            if(digit != 0){
                ans= digit * position + ans;
                position*=10;//increase position
            }
            n= n/10;
        }
        return ans;
    }
};