class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prefixSum(n);
        vector<int>suffixMin(n);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i]= prefixSum[i-1]+nums[i];
        }
        suffixMin[n-1]= nums[n-1];
        for(int i= n-2;i>=0;i--){
            suffixMin[i]= min(nums[i], suffixMin[i+1]);
        }
        long long ans = LLONG_MIN;
        for(int i=0;i<n-1;i++){
            ans = max(prefixSum[i] - suffixMin[i+1], ans);
        }
        return ans;
    }
};