class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mp(k,0);
        for(int &num :arr){
            int rem = ((num % k) + k) % k; // Ensure remainder is positive
            mp[rem]++;

        }
        if(mp[0]%2!=0){
            return false;  // frequency of zero remainder
        }
        for(int rem=1 ;rem<=k/2;rem++){
            int counterhalf=k-rem;
            if(mp[counterhalf]!=mp[rem]){
                return false;
            }
        }
        return true;


    }
};