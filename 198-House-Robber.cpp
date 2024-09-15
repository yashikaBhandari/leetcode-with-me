class Solution {
public:
int fun(vector<int>& nums, int n, vector<int>& dp) {
    if (n <= 0) return 0; // Base case: No houses left to rob
    if (dp[n] != -1) return dp[n]; // If already computed, return memoized result

    // Either skip the current house or rob it and add result of (n-2)
    return dp[n] = max(fun(nums, n - 1, dp), nums[n - 1] + fun(nums, n - 2, dp));
}
    int rob(vector<int>& nums) {
        //either consider (n-1) house or not
        // amount1 =not considering n-1 house left n-1 house for theif 
        // amount2=do robbery in n-1 th house left n-2 houses for roberry 
        int n = nums.size(); // Get the size of the vector
    if (n == 0) return 0; // No houses to rob

    // Initialize dp vector with -1
    vector<int> dp(n + 1, -1);

    // Call the function for the full array
    return fun(nums, n, dp);

    }
};