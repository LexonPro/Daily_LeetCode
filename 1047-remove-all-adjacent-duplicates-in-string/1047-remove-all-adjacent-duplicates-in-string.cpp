class Solution {
public:
    string removeDuplicates(string s) {
       stack<char> st;
       for(int i = 0 ; i < s.size() ; i++){
        if(st.empty()) st.push(s[i]);
        else if(st.top() == s[i]){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
       }
        stack<char> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        string temp1 = "";
        while(!temp.empty()){
            temp1 += temp.top();
            temp.pop(); 
        }
        return temp1;
    }
};