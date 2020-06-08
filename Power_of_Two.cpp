'''
class Solution {
public:
    bool isPowerOfTwo(int n) {
// power on 2 cant be 0 and negative
        if(n<=0) return 0;
			// for n to be power of 2 bitwise AND of n & n-1 is 0
        return ((n & (n-1)) == false );        
    }
};
'''
