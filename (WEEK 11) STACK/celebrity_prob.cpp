-----BRUTE FORCE-------- O(N*N) O(N)
class Solution 
{
    public:
    bool rowCheck(int rowIndex,vector<vector<int> >& M){
        for(int col=0;col<M[0].size();col++){
            if(M[rowIndex][col]==1) return false;
        }
        return true;
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        
        if(M.size()==1) return 0;
        
        unordered_map<int,int>mp;
        
        
        for(int i=0;i<M.size();i++){
            for(int j=0;j<M[0].size();j++){
                if(M[i][j]==0) continue;
                
                mp[j]++;
            }
        }
        
        for(auto it:mp){
            if(it.second==n-1){
                if(rowCheck(it.first,M)){
                    return it.first;
                }
            }
        }
        
        return -1;
    }
};

------OPTIMIZED------- O(N) O(2N)

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
       if(M.size()==1) return 0;
        
       vector<int>Indegree(n);
       vector<int>Outdegree(n);
       
       for(int i=0;i<M.size();i++){
           for(int j=0;j<M[0].size();j++){
               if(M[i][j]==1){
                   Indegree[j]++;
                   Outdegree[i]++;
               }
           }
       }
       
       for(int i=0;i<n;i++){
           if(Outdegree[i]==0 && Indegree[i]==n-1){
               return i;
           }
       }
       
       return -1;
    }
};


---BEST---

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