class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s;
        // Push indices in decreasing order of their values in nums
        for (int i = 0; i < nums.size(); i++) {
            if (s.empty() || nums[s.top()] > nums[i]) {
                s.push(i);  // Push index only if the stack is empty or nums[i] is smaller than nums[s.top()]
            }
        }
        
        int ans = 0;
        // Traverse from the right to find the maximum width ramp
        for (int i = nums.size() - 1; i > ans; i--) {
            // Check if we can form a ramp with the current element
            while (!s.empty() && nums[s.top()] <= nums[i]) {
                ans = max(ans, i - s.top());  // Update the maximum width
                s.pop();
            }
        }
        
        return ans;
    }
};