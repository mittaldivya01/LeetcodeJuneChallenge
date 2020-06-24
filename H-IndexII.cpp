class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len=citations.size();
        if(!len)
            return 0;
        int l=0,h=len-1,m=0;
        int ans=0;
        while(l<=h)
        {
            m=l+ (h-l)/2;
            
        if(citations[m]>=len-m)
        {
            ans= len-m;
            h=m-1;
        }
        else
        { 
            l=m+1;
        }             
        }
        return ans;
        
    }
};
