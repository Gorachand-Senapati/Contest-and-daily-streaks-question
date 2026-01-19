class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int,int>>container(n);//store cost with cap
        for(int i=0;i<n;i++){
            container[i] = {costs[i],capacity[i]};
        }
        //now sort according cost
        sort(container.begin(), container.end());
        //make a prefmax which store the max capcity among all machine
        vector<int>prefMax(n);
        prefMax[0]= container[0].second;
        for(int i=1;i<n;i++){
            prefMax[i] = max(prefMax[i-1],container[i].second);//store the best value among all in last
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int cost_i = container[i].first;
            int cap_i = container[i].second;
            //single machine
            if(cost_i < budget){
                ans = max(ans,cap_i);
            }
            //two machine
            int remaining = budget - cost_i -1;//need less than so -1
            if(remaining <= 0) continue;//if 0 or less
            //now binary search for before i and cost need reamining   j < i with cost[j] <= remaining
            int l =0, r = i-1, best = -1;
            while(l<=r) {
                int mid =(l+r)/2;
                if(container[mid].first <= remaining){
                    best = mid;
                    l = mid+1;//go right
                } else {
                    r = mid-1;
                }
            }
            if(best != -1){
                ans = max(ans, cap_i + prefMax[best]);
            }
        }
        return ans;
    }
};