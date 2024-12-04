class Solution {
public:
    bool backspaceCompare(string s, string t) {
       /* stack<int>s1,s2;
        string str1,str2;
        for(int i=0;i<s.size();i++){
            
        
        if(s[i]=='#' && !s1.empty())
        s1.pop();
        else if(s[i]!='#')
        s1.push(s[i]);
        }
        for(int i=0;i<t.size();i++){
             if(t[i]=='#' && !s2.empty())
        s2.pop();
        else if(t[i]!='#')
        s2.push(t[i]);
        }
        while(!s1.empty()){
            str1.push_back(s1.top());
            s1.pop();
        }
         while(!s2.empty()){
            str2.push_back(s2.top());
            s2.pop();
        }
        
        return str1==str2;
*/

// without using extra space optimised solution traverse. from last and count no of # and skip that no of characters 
int m= s.length();
int n=t.length();
int i=m-1;
int j=n-1;

int skip_s=0;
int skip_t=0;
while(i>=0 || j>=0 ){
    while(i>=0){
        if(s[i]=='#'){
            skip_s++;
            i--;
        }
        else if(skip_s>0){
            skip_s--;
            i--;
        }
        else{
            break;
        }

    }
     while(j>=0){
        if(t[j]=='#'){
            skip_t++;
            j--;
        }
        else if(skip_t>0){
            skip_t--;
            j--;
        }
        else{
            break;
        }

    }
    char first=i<0?'$':s[i];
    char sec=j<0?'$':t[j];
    if(first!=sec)
    return  false;
    i--;
    j--;


}
return true;
    }
};

 