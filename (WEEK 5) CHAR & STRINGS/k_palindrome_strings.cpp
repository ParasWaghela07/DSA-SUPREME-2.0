class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k==s.size()) return true;
        if(k>s.size()) return false;
        
        unordered_map<char,int>mp;
        for(auto it:s) mp[it]++;
        
        int bad=0;
        for(auto it:mp){
            if(it.second & 1) bad++;
        }

        return bad<=k;
    }
};