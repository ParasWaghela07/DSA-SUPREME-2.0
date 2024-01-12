
    int byRecursion(int capacity , int wt[] , int val[],int n,int i){
        
        if(i==n-1){
            
            if(wt[i] <= capacity){
                return val[i];
            }
            else{
                return 0;
            }
        }
        
        int include=0;
        if(wt[i] <= capacity){
            include = val[i] + byRecursion(capacity - wt[i] , wt ,val ,n ,i+1);
        }
        int exclude= 0 + byRecursion(capacity, wt ,val ,n ,i+1);
        
        return max(include,exclude);
        
    }
    
    int byMemo(int capacity,int wt[], int val[],int n,int i,vector<vector<int>> &dp){
        if(i==n-1){
            if(wt[i] <= capacity){
                return val[i];
            }
            else{
                return 0;
            }
        }
        if(dp[capacity][i]!=-1){
            return dp[capacity][i];
        }
        int include=0;
        if(wt[i] <= capacity ){
            include= val[i] + byMemo(capacity - wt[i] , wt, val , n ,i+1,dp);
        }
        int exclude=0 + byMemo(capacity, wt, val , n ,i+1,dp);
        
        dp[capacity][i]=max(include,exclude);
        
        return dp[capacity][i];
    }
    
    int byTabu(int capacity,int wt[], int val[],int n,vector<vector<int>> &dp){
        for(int row=0;row<=capacity;row++){
            dp[row][n]=0;
        }
        
        for(int i=0;i<=capacity;i++){
            for(int j=n-1;j>=0;j--){
                 int include=0;
                 if(wt[j]<=i){
                      include= val[j] + dp[i - wt[j] ][j+1];
                  }
        int exclude=0 +  dp[i][j+1];
        dp[i][j]=max(include,exclude);
            }
        }
        
        return dp[capacity][0];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       
    //   int index=0;
    //   int ans=byRecursion(W,wt,val,n,index);
    //   return ans;
       
       
      vector<vector<int>>dp(W+1 , vector<int>(n+1,-1));
    //   int ans = byMemo(W,wt,val,n,index,dp);
    
       int ans=byTabu(W,wt,val,n,dp);
       return ans;
       
    }