//MY SOLUTION && LAKSHAY BHAIYA'S SOLUTION

int countRev (string s)
{
    stack<char>st;
    int steps=0;
    
    if(s.size()%2!=0){
        return -1;
    }
    else{
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(!st.empty() && st.top()=='{'){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        
        while(!st.empty()){
            char temp=st.top();
            st.pop();
            
            if( (temp=='{' && st.top()=='{') || (temp=='}' && st.top()=='}') ){
                steps++;
                st.pop();
            }
            else{
                steps=steps+2;
                st.pop();
            }
        }
        
    }
    
    return steps;

}