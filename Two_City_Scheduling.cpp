class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n = costs.size()/2;
        vector<int> cost_diff;
        int res = 0;
        // res to add total cost to A city 
        // cost saving vector maintained between city B and A
        for(vector<int> cost : costs){
            res += cost[0];
            cost_diff.push_back(cost[1] - cost[0]); 
        }
        sort(cost_diff.begin(), cost_diff.end());
        // add maximum cost saving n index to city B
        for(int i = 0; i < n; i++){
            res += cost_diff[i];
        }
        return res;
    }
};
