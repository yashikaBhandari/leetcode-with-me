class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        int maxscore=0;
        sort(begin(tokens),end(tokens));
        int i=0, j=n-1;
        int score=0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score+=1;
                i++;
                maxscore=max(maxscore,score);
            }
            //maxscore=max(maxscore,score);
            else if(score>=1){
                power+=tokens[j];
                score-=1;
                j--;
            }
            else{
                break;
            }
         //
        }
        return maxscore;
    }

};