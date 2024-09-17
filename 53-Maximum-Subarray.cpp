class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      // to find the subarray with largest sum 
      int sum=0;
      int maxs=nums[0];
      for(int i=0;i<nums.size();i++){
        sum= sum+nums[i];
        maxs=max(maxs,sum);
        if(sum<0){
            sum=0;
        }
    
      } 
          return maxs; 
    }
};