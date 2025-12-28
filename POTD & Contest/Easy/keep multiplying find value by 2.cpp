class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.count(original)) {
            original *= 2;
        }
        return original;
    }
};
// n<=10^3 so here support O(n2) 
// n<=10^5 so here suppor O(nlogn) and best O(n2) not use
// n<=10^6 or more must use O(n) or O(log n)