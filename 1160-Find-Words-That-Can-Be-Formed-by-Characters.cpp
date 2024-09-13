class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // make unorderdset of chars and every ch of word in words is in set if it is then string can be formed by this word 
        unordered_map<char,int>charcount;
        for(char c:chars){
            charcount[c]++;
        }
        int total_length=0;
        for(string word:words){
            unordered_map<char,int>wordcount;
            bool canform=true;
            for(char c:word){
                wordcount[c]++;
                if(wordcount[c]>charcount[c]){
                    canform=false;
                    break;
                }

            }
            // if word can be formed
            if(canform){
                total_length+=word.length();
            }
        }
        return total_length;
    }
};