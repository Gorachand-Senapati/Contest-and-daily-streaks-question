3862. Find the Smallest Balanced Index

class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();int ans =-1;
        vector< long long >prefixSum(n,0);
        prefixSum[0]= nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i]= prefixSum[i-1] + nums[i];
        }
        unsigned long long prod =1;//store very large non negative integer
       
       for(int i=n-1;i>=1;i--){
        if(prod == prefixSum[i-1]){
            ans = i;
        }
        if(prod > prefixSum[n-1]) break;//when prod is more than sum
        prod = prod * nums[i];
       }
       return ans;
    }
};