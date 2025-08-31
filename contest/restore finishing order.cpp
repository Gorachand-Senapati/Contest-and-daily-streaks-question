//lc- 3668
class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> mp(friends.begin(), friends.end()); // step 1
    vector<int> ans;
    for (int x : order) { // step 2
        if (mp.count(x)) ans.push_back(x);
    }
        return ans;
    }
};