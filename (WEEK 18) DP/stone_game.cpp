class Solution {
public:
    bool byRec(vector<int>&piles,int s,int e,int alice,bool flag){
        if(s>e){
            return alice>0;
        }

        if(flag){
            return byRec(piles,s+1,e,alice+piles[s],false) || byRec(piles,s,e-1,alice+piles[e],false);
        }
        else{
            return byRec(piles,s+1,e,alice-piles[s],true) || byRec(piles,s,e-1,alice-piles[e],true);
        }
    }

    bool byRec(vector<int>&piles,int s,int e,int alice){
        if(s>=e){
            return alice>0;
        }

        bool op1=byRec(piles,s+2,e,alice+piles[s]-piles[s+1]);
        bool op2=byRec(piles,s+1,e-1,alice+piles[s]-piles[e]);
        bool op3=byRec(piles,s,e-2,alice+piles[e]-piles[e-1]);
        bool op4=byRec(piles,s,e-1,alice+piles[e]-piles[s]);

        return op1||op2||op3||op4;
    }

    bool byMem(vector<int>&piles,int s,int e,int alice,map<vector<int>,bool>&dp){
        if(s>=e){
            return alice>0;
        }

        if(dp.find({s,e,alice})!=dp.end()){
            return dp[{s,e,alice}];
        }

        bool op1=byMem(piles,s+2,e,alice+piles[s]-piles[s+1],dp);
        bool op2=byMem(piles,s+1,e-1,alice+piles[s]-piles[e],dp);
        bool op3=byMem(piles,s,e-2,alice+piles[e]-piles[e-1],dp);
        bool op4=byMem(piles,s,e-1,alice+piles[e]-piles[s],dp);

        return dp[{s,e,alice}]=op1||op2||op3||op4;
    }
    bool stoneGame(vector<int>& piles) {

        // return true; --> solution
        int s=0;
        int e=piles.size()-1;

        // return byRec(piles,s,e,0,true);

        // return byRec(piles,s,e,0);

        map<vector<int>,bool>dp;
        return byMem(piles,s,e,0,dp);

    }
};