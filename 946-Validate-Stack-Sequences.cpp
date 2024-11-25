class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      // we will pop from stack only when that same element is present on the top of stack
      stack<int>st;
      int m=pushed.size();
      int i=0,j=0;
      while(i<m && j<m){
        st.push(pushed[i]);
        while(!st.empty() && j<m && st.top()== popped[j]){
        st.pop();
        j++;
      }  
      i++;
    }
    return st.empty();
    }
};