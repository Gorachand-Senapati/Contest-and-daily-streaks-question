class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n= nums.size();
        if(n <3)return -1;
        int dist= INT_MAX; 
        bool isFound = false;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k= j+1;k<n;k++){
                    if(nums[i]== nums[j] && nums[j]== nums[k]){
                        isFound= true;
                      int ans = abs(i-j) + abs(j-k) + abs(k-i);
                      dist=min(dist, ans);
                    } 
                }
            }
        }
        return isFound ? dist: -1;
    }
};

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        if (n < 3) return -1;

        for (int i = 0; i < n; ++i) mp[nums[i]].push_back(i);

        int dist = INT_MAX;
        bool found = false;

        for (auto &p : mp) {
            auto &v = p.second;
            int m = v.size();
            if (m < 3) continue;

            // sliding window of size 3 over sorted indices
            for (int i = 0; i + 2 < m; ++i) {
                int span = v[i+2] - v[i];      // last - first in the triple
                int d = 2 * span;             // |a-b|+|b-c|+|c-a| = 2*(c-a)
                dist = min(dist, d);
                found = true;
            }
        }

        return found ? dist : -1;
    }
};
// n<=10^3 so here support O(n2)
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        if (n < 3) return -1;

        for (int i = 0; i < n; ++i) mp[nums[i]].push_back(i);

        int dist = INT_MAX;
        bool found = false;

        for (auto &p : mp) {
            auto &v = p.second;
            int m = v.size();
            if (m < 3) continue;

            // sliding window of size 3 over sorted indices
            for (int i = 0; i + 2 < m; ++i) {
                int span = v[i+2] - v[i];      // last - first in the triple
                int d = 2 * span;             // |a-b|+|b-c|+|c-a| = 2*(c-a)
                dist = min(dist, d);
                found = true;
            }
        }

        return found ? dist : -1;
    }//TC= O(n2) SC= O(n)
};
// n<=10^5 so here suppor O(nlogn) and best O(n2) not use 