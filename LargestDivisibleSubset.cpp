class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& A) {
        int n = A.size();
      
     if(n == 0)
         return {};
      sort(A.begin(), A.end()); 
    int max_ind = 0;  
      vector<int> dp(n, 1);      
      vector<int> previous_index(n, -1);
       for(int i=1; i<n; i++) {
           for(int j=0; j<i; j++) {
               if(A[i]%A[j]==0 and dp[i] < dp[j] + 1) {
                   dp[i] = dp[j]+1;
                   previous_index[i] = j;
               }
           }
           if(dp[i] > dp[max_ind]) {
               max_ind = i;
           }
       }
        int t = max_ind;  
      vector<int> answer;      
      while(t >= 0) {
          answer.push_back(A[t]);
          t = previous_index[t];
      }      
        reverse(answer.begin(),answer.end());
      return answer;          
    }
};
