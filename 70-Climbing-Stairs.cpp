class Solution {
public:
    int climbStairs(int n) {
       // to reach top it takes n stairs or steps which is given as input 
       // total ways to reach (n-1) step + total ways to reach (n-2) steps 

      // base condition if(n<=2) return n;

     /* vector<int>dp(n+1,-1);
      if(dp[n]!=-1) return dp[n];
      if(n<=2){
      return dp[n]=n;
      }
      return dp[n]=climbStairs(n-1)+climbStairs(n-2);

*/
// space optimisation
if (n == 1) return 1;
        
        int prev2 = 1; // Ways to reach step 1
        int prev1 = 2; // Ways to reach step 2
        
        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2; // Current step = (n-1) + (n-2)
            prev2 = prev1; // Update for the next iteration
            prev1 = current;
        }
        
        return prev1;

    }
};