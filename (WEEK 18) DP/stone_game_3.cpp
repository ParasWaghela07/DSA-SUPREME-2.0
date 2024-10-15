class Solution {

//OWN

public:
    int byRec(vector<int>&stones,int index){
        if(index>=stones.size()){
            return 0;
        }

        int ans=INT_MIN;
        int temp=0;

        for(int i=index;i<index+3;i++){
            if(i>=stones.size()) break;
            temp+=stones[i];

            int bobAns=temp - byRec(stones,i+1);

            ans=max(ans,bobAns);        
        }
        return ans;
    }

    int byMem(vector<int>&stones,int index,vector<int>&dp){
        if(index>=stones.size()){
            return 0;
        }

        if(dp[index]!=-1) return dp[index];

        int ans=INT_MIN;
        int temp=0;

        for(int i=index;i<index+3;i++){
            if(i>=stones.size()) break;
            temp+=stones[i];

            int bobAns=temp - byMem(stones,i+1,dp);

            ans=max(ans,bobAns);        
        }
        return dp[index]=ans;
    }

    int byTabu(vector<int>&stones){
        vector<int>dp(stones.size()+1,0);
        for(int index=stones.size()-1;index>=0;index--){
            int ans=INT_MIN;
            int temp=0;

            for(int i=index;i<index+3;i++){
                if(i>=stones.size()) break;
                temp+=stones[i];

                int bobAns=temp - dp[i+1];

                ans=max(ans,bobAns);        
            }
            dp[index]=ans;
        }

        return dp[0];
    }

    int bySO(vector<int>&stones){
        int next1=0;
        int next2=0;
        int next3=0;

        for(int index=stones.size()-1;index>=0;index--){
            int ans=INT_MIN;
            int temp=0;

            for(int i=index;i<index+3;i++){
                if(i>=stones.size()) break;
                temp+=stones[i];

                int whos_next=0;
                if(i==index) whos_next=next1;
                if(i==index+1) whos_next=next2;
                if(i==index+2) whos_next=next3;

                int bobAns=temp - whos_next;

                ans=max(ans,bobAns);        
            }
            next3=next2;
            next2=next1;
            next1=ans;
        }
        return next1;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        // int score=byRec(stoneValue,0);

        // vector<int>dp(stoneValue.size()+1,-1);
        // int score=byMem(stoneValue,0,dp);

        // int score=byTabu(stoneValue);

        int score=bySO(stoneValue);

        if(score>0) return "Alice";
        else if(score<0) return "Bob";
        else return "Tie";
    }
};