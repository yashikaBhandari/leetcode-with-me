class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
      long long sum=0;
      priority_queue<int>pq(nums.begin(),nums.end());
      while(k--){
        int maxi=pq.top();
        pq.pop();
        sum+=maxi;
        maxi=ceil(maxi/3.0);
        pq.push(maxi);

      } 
      return sum ;

    }
};