class Solution {
public:


    int numSquares(int n) {
        static vector<int>dp(10001,-1);
        if(n<=0) return 0;
        if(dp[n]!=-1) return dp[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int sqnum=i*i;
            int count=1+numSquares(n-sqnum);
            ans=min(ans,count);
        }
        return dp[n]=ans;
    }
};