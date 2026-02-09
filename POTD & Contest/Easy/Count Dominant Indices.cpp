class Solution {//bfa O(n^2) tc and O(1) sc
public:
    int dominantIndices(vector<int>& nums) {
        int n= nums.size(), ans =0;
        for(int i=0;i<n-1;i++){
            int num = nums[i];
            int cnt =0, sum =0;
            for(int j=i+1;j<n;j++){
                sum+= nums[j];
                cnt++;
            }
            if(num > (sum/cnt)) ans++;
        }
        return ans;
    }
};

//optimise solution O(n) tc and O(1) sc
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int totalSum =0;
        for(int x: nums)totalSum+=x;
        int prefixSum =0, ans= 0;
        for(int i=0;i<n-1;i++){
            int rightSum = totalSum -prefixSum-nums[i];
            int cnt = n-i-1;//how much number in right side
            if(nums[i] * cnt > rightSum) ans++; //instead of doing sum/cnt we can do num*cnt > sum to avoid floating point division
            prefixSum+=nums[i];
        }
        return ans;
    }
};