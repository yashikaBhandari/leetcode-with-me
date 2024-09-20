class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // we will check future temperatures when it will be warmer than current element 
        // iterate from last if its smaller than pop it , it is of no use, for last element then there will be no future temp for it , keep zero for it , for temp[i] if temp[st.top()] is greater than it than push it in ans . push that temp[i] in stack also because that temp can be greater temp for next 

        int n=temperatures.size();
        vector<int>ans(n,0);
        stack<int>st{};
        for(int i=n-1;i>=0;--i){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i])
            st.pop();

            if(!st.empty())
            ans[i]=st.top()-i;
            st.push(i);
        }
        return ans;

    }
};