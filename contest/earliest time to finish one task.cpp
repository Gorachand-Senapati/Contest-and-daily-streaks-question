class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
       int ans = INT_MAX;
        for(auto& task: tasks){
            int finish=task[0]+task[1];//s[i]+t[i]
            ans= min(ans, finish);
        }
        return ans;
    }
};