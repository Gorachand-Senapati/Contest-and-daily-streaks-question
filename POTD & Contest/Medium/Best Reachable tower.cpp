class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int temp = INT_MIN;
        for(auto it:towers){
            int x = it[0];
            int y = it[1];
            int qf = it[2];
            if((abs(x-center[0]) + abs(y-center[1])) <= radius){
                temp = max(temp, qf);
            }
        }
        if(temp == INT_MIN) return {-1,-1};
        vector<int>ans;
        bool found = false;
         for(auto it:towers){
            int x = it[0];
            int y = it[1];
            int qf = it[2];
            if(qf == temp){
                if(!found || make_pair(x,y) < make_pair(ans[0],ans[1])) {
                    ans = {x,y};
                    found = true;
                }
            }
        }
        return ans;
    }
};