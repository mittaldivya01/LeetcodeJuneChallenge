class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(m1.find(nums[i])==m1.end())
                m1.insert(make_pair(nums[i],1));
            else
                ++m1[nums[i]];
                
        }
        for(auto it:m1)
        {
           if(it.second == 1 )
               return it.first;
        }
        return 0;
    }
};
