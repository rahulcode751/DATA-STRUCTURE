class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(int i=0;i<tokens.size();i++){
            
        if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
              /// 2 elements
             int v1 = st.top();
            st.pop();
            int v2 = st.top();
            st.pop();
            
            if(tokens[i]=="+"){
                st.push(v2+v1);  /// push result inside stack
            } 
            else if(tokens[i]=="-"){
                st.push(v2-v1);  /// push result inside stack
            }
             else if(tokens[i]=="*"){
                st.push(v2*v1);  /// push result inside stack
            }
             else if(tokens[i]=="/"){
                st.push(v2/v1);  /// push result inside stack
            }
        }
        
        else {
            /// operands
            st.push(atoi(tokens[i].c_str()));
        }
    }
        
    /// one element inside the stack
        
        return st.top();
    }       
            
};
