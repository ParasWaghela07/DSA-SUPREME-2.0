//OWN BACKTRACKING

class Solution {
public:
    void solve(string&s,unordered_map<string,int>&mp,string word,int index,vector<string>&ans){
        if(index>=s.size()){
            ans.push_back(word.substr(1,word.size()));
            return;
        }

        string temp="";

        for(int i=index;i<s.size();i++){
            temp.push_back(s[i]);
            if(mp.find(temp)!=mp.end()){
                solve(s,mp,word+' '+temp,i+1,ans);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        for(auto it:wordDict){
            mp[it]++;
        }

        string word="";
        vector<string>ans;
        solve(s,mp,word,0,ans);

        return ans;
    }
};

// DP
class Solution {
public:
    vector<string>byRec(string &s,unordered_map<string,int>&mp,int index){
        if(index>=s.size()) return {""};

        string word;
        vector<string>ans;

        for(int i=index;i<s.size();i++){
            word.push_back(s[i]);
            if(mp.find(word)!=mp.end()){
                vector<string>restAns=byRec(s,mp,i+1);

                for(auto it:restAns){
                    if(it.size()>0){
                        ans.push_back(word+' '+it);
                    }
                    else{
                        ans.push_back(word);
                    }
                }
            }
        }

        return ans;
    }

    vector<string>byMem(string &s,unordered_map<string,int>&mp,int index,unordered_map<int,vector<string>>&dp){
        if(index>=s.size()) return {""};
        if(dp.find(index)!=dp.end()) return dp[index];

        string word;
        vector<string>ans;

        for(int i=index;i<s.size();i++){
            word.push_back(s[i]);
            if(mp.find(word)!=mp.end()){
                vector<string>restAns=byMem(s,mp,i+1,dp);

                for(auto it:restAns){
                    if(it.size()>0){
                        ans.push_back(word+' '+it);
                    }
                    else{
                        ans.push_back(word);
                    }
                }
            }
        }

        return dp[index]=ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        for(auto it:wordDict) mp[it]++;

        // return byRec(s,mp,0);

        unordered_map<int,vector<string>>dp;
        return byMem(s,mp,0,dp);
    }
};