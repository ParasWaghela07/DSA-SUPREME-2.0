
class Solution {
public:
    bool byRec(string &s,unordered_map<string,int>&mp,int index){
        if(index>=s.size()){
            return true;
        }

        string word="";
        bool ans=false;

        for(int i=index;i<=s.size();i++){
            word.push_back(s[i]);
            if(mp.find(word)!=mp.end()){
                ans=ans || byRec(s,mp,i+1);
            }
        }

        return ans;
    }


    bool byMem(string &s,unordered_map<string,int>&mp,int index,vector<int>&dp){
        if(index>=s.size()){
            return true;
        }

        if(dp[index]!=-1) return dp[index];

        string word="";
        bool ans=false;

        for(int i=index;i<s.size();i++){
            word.push_back(s[i]);
            if(mp.find(word)!=mp.end()){
                ans=ans || byMem(s,mp,i+1,dp);
            }
        }

        return dp[index]=ans;
    }

    bool byTabu(string &s,unordered_map<string,int>&mp){
        vector<int>dp(s.size()+1,1);

        for(int index=s.size()-1;index>=0;index--){
            string word="";
            bool ans=false;

            for(int i=index;i<s.size();i++){
                word.push_back(s[i]);
                if(mp.find(word)!=mp.end()){
                    ans=ans ||dp[i+1];
                }
            }

            dp[index]=ans;
        }

        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        for(auto it:wordDict){
            mp[it]++;
        }
        // return byRec(s,mp,0);'

        // vector<int>dp(s.size()+1,-1);
        // return byMem(s,mp,0,dp);

        return byTabu(s,mp);
    }
};




class Solution {
public: 

    // OWN BUT TILL ONLY REC N  MEMO
    bool byRec(string str,unordered_map<string,int>&mp){
        if(mp[str]) return true;
        if(str.size()==1) return false;

        bool ans=false;
        for(int i=0;i<str.size()-1;i++){
            if(byRec(str.substr(0,i+1),mp) && byRec(str.substr(i+1,str.size()),mp)){
                ans=true;
                break;
            }
        }

        return ans;
    }

    bool byRec(string &str,unordered_map<string,int>&mp,int s,int e){
        string temp;
        for(int i=s;i<=e;i++){
            temp.push_back(str[i]);
        }
        
        if(mp.find(temp) != mp.end()) return true;
        if(temp.size()==1) return false;

        bool ans=false;
        for(int i=s;i<e;i++){
            if(byRec(str,mp,s,i) && byRec(str,mp,i+1,e)){
                ans=true;
                break;
            }
        }

        return ans;
    }

    bool byMem(string &str,unordered_map<string,int>&mp,int s,int e,vector<vector<int>>&dp){
        if(dp[s][e]!=-1) return dp[s][e];

        string temp;
        for(int i=s;i<=e;i++){
            temp.push_back(str[i]);
        }
        
        if(mp.find(temp) != mp.end()) return true;
        if(temp.size()==1) return false;

        bool ans=false;
        for(int i=s;i<e;i++){
            if(byMem(str,mp,s,i,dp) && byMem(str,mp,i+1,e,dp)){
                ans=true;
                break;
            }
        }

        return dp[s][e]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        for(auto it:wordDict){
            mp[it]++;
        }

        // return byRec(s,mp,0,s.size()-1);

        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return byMem(s,mp,0,s.size()-1,dp);
    }
};