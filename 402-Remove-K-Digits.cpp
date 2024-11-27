class Solution {
public:
    string removeKdigits(string num, int k) {
       // leep the digits in increasind order if it become decreasing pop back previous element 
       string result;
       int n=num.length();
       for(int i=0;i<n;i++){
        while(!result.empty() && result.back()>num[i] && k>0){
            result.pop_back();
            k--;
        }
        if(result.length()>0 || num[i]!='0'){
            // to avoid the case we have preceding zeroes 
            result.push_back(num[i]);
        }
       } 
       while(k>0 && !result.empty()){
        result.pop_back();
        k--;
       }
       if(result.empty()){
        return "0";
       }
       return result;
    }
};