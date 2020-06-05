class Solution {
private:
    vector<int> v;
public:
    Solution(vector<int> w) {
        for(int i=0; i<w.size(); i++)
            v.size()==0 ? v.push_back(w[i]): v.push_back(w[i]+v.back());
    }
    
    int pickIndex() {
        int totalWeight = v.back();
        int k = rand() % totalWeight;
        auto itr = upper_bound(v.begin(),v.end(),k);
        return itr - v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
