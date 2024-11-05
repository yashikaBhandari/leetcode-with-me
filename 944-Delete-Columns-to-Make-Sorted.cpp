class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // every first letter of every word would be column 1 elements so compare them 
        int count=0;
        for(int i=0;i<strs[0].size();i++){
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]<strs[j-1][i]){
                count++;
                break;
            }
        }
        }
        return count;

    }
};