class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
 vector<int> decending = nums;
        // Step 2: sort in decreasing order
        sort(decending .begin(), decending .end(), greater<int>());
        vector<int> ans;
        for (int i = 0; i < decending .size() && k > 0; i++) {
            if (ans.empty() || ans.back() != decending [i]) {
                ans.push_back(decending [i]);
                k--;  // picked one distinct
            }
        }
        return ans; // already in descending order
    }
};