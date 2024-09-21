bool comp(string a, string b){
    if(a+b>b+a)return true;
    return false;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        vector<string>str;
        for(int x:nums){
            str.push_back(to_string(x));
        }
        sort(str.begin(),str.end(),comp);
        for(string x:str){
            ans.append(x);
        }
        // edge case
        int start=0;
        while(ans[start]=='0' && start<ans.size()-1)start++;
        return ans.substr(start);
        return ans;
    }
};