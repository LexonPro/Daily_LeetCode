class Solution {
public:
    int calPoints(vector<string>& operations) {
       int sum = 0;
       stack<int> st;
       for(int i = 0; i < operations.size();i++){
            if(operations[i] == "+"){
                int temp = st.top();
                st.pop();
                int temp2 = st.top() + temp;
                st.push(temp);
                st.push(temp2);
            }
            else if(operations[i] == "C"){
                st.pop();
            }
            else if(operations[i] == "D"){
                st.push(2 * st.top());
            }
            else{
                st.push(stoi(operations[i]));
            }
            
            }
            while(!st.empty()){
                sum += st.top();
                st.pop();
       } 
       return sum;
    }
};