class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=1;
        int maxp=nums[0];
        for(int i=0;i<nums.size();i++){
            prod=prod*nums[i];
            maxp=max(maxp,prod);
            if(prod==0)
            prod=1;
        }
        prod=1;
         for(int i=nums.size()-1;i>=0;i--){
            prod=prod*nums[i];
            maxp=max(maxp,prod);
            if(prod==0)
            prod=1;
        }
        return maxp;
    }
};