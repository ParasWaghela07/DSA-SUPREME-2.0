int countRev (string s)
{
    
    if(s.size()&1) return -1;
    
     stack<char>st;
     
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
     
     int count=0;
     
     while(!st.empty()){
         char top1=st.top();
         st.pop();
         
         char top2=st.top();
         st.pop();
         
         if(top1==top2){
             count+=1;
         }
         else{
             count+=2;
         }
         
     }
     
     return count;
}