class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=prices[0];
        int maxprofit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<minprice){
                minprice=prices[i];

            }
            else{
                maxprofit=max(maxprofit,prices[i]-minprice);
            }
        }
        return maxprofit;
    }
};