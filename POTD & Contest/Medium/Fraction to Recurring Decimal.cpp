class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        if (numerator == 0) return "0";
        if( (long long )numerator *  (long long) denominator < 0){
            res+='-';
        }
        long long absnumerator= labs(numerator);
        long long absdenominator= labs(denominator);

        long long intdivisor = absnumerator / absdenominator;
        long long remain= absnumerator % absdenominator;
        res+=to_string(intdivisor);
        if(remain== 0) return res;

        res+='.';
        unordered_map<long long, int>mp;

        while(remain != 0){
            if(mp.count(remain)){
                res.insert(mp[remain], "(");
                res+=")";
                break;
            }
            //if not get
            mp[remain] = res.length();
            remain*= 10;
            int digit= remain /absdenominator;
            res+=to_string(digit);
            remain= remain % absdenominator;
        }
        return res;
    }
}; 