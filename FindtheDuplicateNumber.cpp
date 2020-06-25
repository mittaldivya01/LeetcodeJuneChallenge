class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() <2)
            return 0;
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i])==s.end())
                s.insert(nums[i]);
            else
                return nums[i];
        }
        
     return 0;   
    }
};

int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        slow = nums[slow];
        fast = nums[nums[fast]];
		//FLOYD HARE & TORTOISE ALGO
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
		// FINDING STARTING POINT OF CYCLE
        int start = nums[0];
        while(start != slow)
        {
            start = nums[start];
            slow = nums[slow];
        }
        return start;
    }
