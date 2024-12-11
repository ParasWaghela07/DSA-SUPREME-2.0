class Solution {
public:
    ---OPTIMIZED---
    int maximumLength(string s) {
        vector<vector<int>>matrix(26,vector<int>(s.size()+1,0));

        int l=0;
        char prevChar=s[0];

        for(int i=0;i<s.size();i++){
            char currChar=s[i];

            if(prevChar==currChar){
                l++;
                matrix[currChar-'a'][l]++;
            }
            else{
                l=1;
                matrix[currChar-'a'][l]++;
                prevChar=currChar;
            }
        }

        int ans=-1;
        for(int i=0;i<matrix.size();i++){
            int cumSum=0;
            for(int j=s.size();j>=1;j--){
                cumSum+=matrix[i][j];
                if(cumSum>=3){
                    ans=max(ans,j);
                    break;
                }
            }
        }

        return ans;
    }
};

--BETTER BRUTE--
class Solution {
public:
    int maximumLength(string s) {
        map<pair<char,int>,int>mp;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            int l=0;
            for(int j=i;j<s.size();j++){
                if(s[j]==ch){
                    l++;
                    mp[{ch,l}]++;
                }
                else break;
            }
        }

        int ans=-1;
        for(auto it:mp){
            int len=it.first.second;
            int frq=it.second;

            if(frq>=3 && len>ans) ans=len;
        }

        return ans;
    }
};

--BRUTTEST FORCE--
class Solution {
public:
    bool isSpecial(string &str){
        char c=str[0];
        for(auto it:str) if(it!=c) return false;

        return true;
    }
    int maximumLength(string s) {
        unordered_map<string,int>mp;
        for(int i=0;i<s.size();i++){
            string temp;
            for(int j=i;j<s.size();j++){
                temp.push_back(s[j]);
                mp[temp]++;
            }
        }

        int ans=-1;
        for(auto it:mp){

            if(it.second>=3){
                int t=it.first.size();
                string str=it.first;
                if(isSpecial(str))ans=max(ans,t);
            }
        }

        return ans;
    }
};

--