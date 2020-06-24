class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        int factorial=1, N=n;
        string ans="";
        for(int i=1;i<=n;i++){
            v.push_back(i);
            factorial*=i;
        }
        while(n){
            int factor=factorial/n;
            int pick = k%factor==0 ? k/factor-1 : k/factor;
            k=k%factor ? k%factor : factor;
            ans+=(v[pick]+'0');
            v.erase(v.begin()+pick);
            factorial/=n--;
        }
        return ans;
    }
};
