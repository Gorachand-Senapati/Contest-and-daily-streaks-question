class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>result;//store ans
        for(int num: nums){//processing left to right 
//we touch a num twice push and pop so O(2n) and for gcd total TC= O(n log min(a,b))
            while(!result.empty()){
                int curr= num;
                int prev= result.back();
                int GCD= gcd(curr, prev);//log( min(a,b))
                if(GCD==1)break;
                result.pop_back();
                int LCM= prev/GCD *curr;//(prev*curr)/gcd
                num= LCM;
            }
            result.push_back(num);
        }
        return result;
    }
};