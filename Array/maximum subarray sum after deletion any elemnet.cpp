//3487 

// class Solution {
// public:
//     int maxSum(vector<int>& nums) {
//         int n = nums.size();
//         int sum =0;
//         sort(nums.begin(), nums.end());
//         for(int i=0;i<n;i++){
//              if (nums[i] > 0 && (i == 0 || nums[i] != nums[i - 1])){
//                 sum+=nums[i];
//             }
            
//         }
//         return sum;
//     }
// };

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        if (mx <= 0)    return mx;

        unordered_set<int> seen;
        int ans = 0;
        for (int x : nums) {
            if (x > 0 && !seen.count(x)) {
                ans += x;
                seen.insert(x);
            }
        }
        return ans;
    }
};