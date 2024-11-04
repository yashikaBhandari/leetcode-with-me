class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int index=0;
        int i=0;
        while(i<n){
            char curr_char=chars[i];
            int count=0;
            // find count of duplicates 
            while(i<n && chars[i]==curr_char){
                count++;
                i++;
            }
            //now do assign 
            chars[index]=curr_char;
            index++;
            // convert into string 

            if(count>1){
                string count_str=to_string(count);
                // find digits in string assign in index
                for(char &ch : count_str){
                    chars[index]=ch;
                    index++;
                }
            }
        }
        return index;

    }
};