class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_set<int> seen;
        int n = nums.size();
        int i = n - 1;
        // move from right to left until duplicate appears
        while (i >= 0) {
            if (seen.count(nums[i])) break;
            seen.insert(nums[i]);
            i--;
        }
        // elements to remove = i + 1
        int remove = i + 1;//how many elements before suffix with distinct elements for 0 based index so i+1
        // each operation removes 3 elements
        return (remove + 2) / 3;//ceil value means 1.33= 1 2.456=2 ceil(a / b) = (a + b - 1) / b
    }
};