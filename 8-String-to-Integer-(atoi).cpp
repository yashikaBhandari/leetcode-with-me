/*class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0)
        return 0;
        int i=0;
        // start traversing the string 
        while(i<s.size()&& s[i]==' '){
            i++;
        }
        s=s.substr(i);
        int sign=+1;
        long ans=0;
        if(s[0]=='-'){
            sign=-1;
        }
        int MAX=INT_MAX;
        int MIN=INT_MIN;
        i=(s[0]=='+'|| s[0]=='-')?1:0;
        while(i<s.length()){
            if(s[0]==' '|| !isdigit(s[i])) break;
        }
        ans=ans*10+s[i]-'0';
        if(sign==-1 && -1*ans<MIN)
        return MIN;

        if(sign==+1 && ans>MAX) return MAX;
        i++;

    }
    return (int)(sign*ans);

};*/
class Solution {
public:
    int myAtoi(string s) {
        if (s.length() == 0)
            return 0;

        int i = 0;
        // Skip leading whitespaces
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Handle sign
        int sign = 1;
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long ans = 0;
        int MAX = INT_MAX, MIN = INT_MIN;

        // Convert digits to number
        while (i < s.size() && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // Handle overflow
            if (sign == 1 && ans > MAX) return MAX;
            if (sign == -1 && -ans < MIN) return MIN;

            i++;
        }

        return (int)(sign * ans);
    }
};
