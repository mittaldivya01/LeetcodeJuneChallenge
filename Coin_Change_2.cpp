// DP solution:  
public:
    int change(int amount, vector<int>& coins) {
        int dp[coins.size()+1][amount+1];
        for (int j = 0; j <= coins.size(); j++)    
                dp[j][0] = 1;
        for (int i = 1; i <= amount; i++)
            dp[0][i] = 0;
            
        for (int j = 1; j <= coins.size(); j++) {
            dp[j][0] = 1;
            for (int i = 1; i <= amount; i++) {
                dp[j][i] = dp[j - 1][i];
                if (i - coins[j - 1] >= 0) {
                    dp[j][i] += dp[j][i - coins[j - 1]];
                }
            }
        }
        return dp[coins.size()][amount];        
    }
	
	// Recursive Solution giving TLE 
    private:
    int possible(int amount, vector<int>& coins, int i) {
        
        if(amount<0)
            return 0;
        if(amount==0)
            return 1;
        if(i>coins.size()-1 && amount>0)
            return 0;
        return possible(amount-coins[i], coins,i)+ possible(amount, coins,i+1);
     
    }
public:
    int change(int amount, vector<int>& coins) {
        return possible(amount, coins,0);
      }
};
