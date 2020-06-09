class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lent=t.length();
        int lens=s.length();
        int i=0,j=0;
        while(i<lens && j<lent){
            if(s[i]==t[j])
                ++i;
            ++j;                    
        }                      
        return i==lens;
    }
};
