int evaluatePostfix(string S)
    {
        stack<int>st;
        for(auto it:S){
            if(it=='+' || it=='-' || it=='*' ||it=='/'){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                
                if(it=='+') st.push(b+a);
                else if(it=='-') st.push(b-a);
                else if(it=='*') st.push(b*a);
                else st.push(b/a);
            }
            else{
                st.push(it-'0');
            }
        }
        
        return st.top();
    }