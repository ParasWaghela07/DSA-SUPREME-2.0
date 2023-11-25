
int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        
        //pushing all the members in stack ie. 0,1,2...
        
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        //comapring top 2 members , as they know each other or not
        
        while(st.size()!=1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            
            if(M[a][b]){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        
        //checking the remaining 1 person in stack is celebrity or not
        
        int celeb=st.top();
        st.pop();
        
        //celeb row should be 0 only , so celeb knows nobody
        
        for(int i=0;i<n;i++){
            if(M[celeb][i]!=0){
                return -1;
            }
        }
        
        //celeb col should be 1 only , so everyone knows celeb
        
        for(int i=0;i<n;i++){
            if(M[i][celeb]!=1 && i!=celeb){
                return -1;
            }
        }
        
        return celeb;
        
        
    }