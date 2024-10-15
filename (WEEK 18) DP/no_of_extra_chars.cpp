class Solution {
public:
    int byRec(string&s,unordered_map<string,int>&mp,int index){
        if(index>=s.size()){
            return 0;
        }

        int extra=INT_MAX;
        string word="";
        for(int i=index;i<s.size();i++){
            word.push_back(s[i]);
            if(mp.find(word)!=mp.end()){
                extra=min(extra,byRec(s,mp,i+1));
            }
        }
        extra=min(extra,1+byRec(s,mp,index+1));

        return extra;
    }
    int byMem(string&s,unordered_map<string,int>&mp,int index,vector<int>&dp){
        if(index>=s.size()){
            return 0;
        }

        if(dp[index]!=-1) return dp[index];

        int extra=INT_MAX;
        string word="";
        for(int i=index;i<s.size();i++){
            word.push_back(s[i]);
            if(mp.find(word)!=mp.end()){
                extra=min(extra,byMem(s,mp,i+1,dp));
            }
        }
        extra=min(extra,1+byMem(s,mp,index+1,dp));

        return dp[index]=extra;
    }

    int byTabu(string&s,unordered_map<string,int>&mp){
        vector<int>dp(s.size()+1,0);

        for(int index=s.size()-1;index>=0;index--){
            int extra=INT_MAX;
            string word="";
            for(int i=index;i<s.size();i++){
                word.push_back(s[i]);
                if(mp.find(word)!=mp.end()){
                    extra=min(extra,dp[i+1]);
                }
            }
            extra=min(extra,1+dp[index+1]);

            dp[index]=extra;
        }

        return dp[0];
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int>mp;
        for(auto it:dictionary){
            mp[it]++;
        }

        // return byRec(s,mp,0);

        // vector<int>dp(s.size()+1,-1);
        // return byMem(s,mp,0,dp);

        return byTabu(s,mp);
    }
};