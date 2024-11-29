class Solution {
public:
bool helper(vector<int> nums, int thresh,int mid){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]%mid==0)
        {
            sum+=nums[i]/mid;
        }
        else{
            sum+=nums[i]/mid+1;
        }
    }
    return sum<=thresh;
}

    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int ans=0;
        int e=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2; 
            if(helper(nums,threshold,mid))
            {
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;

    }
};