class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;

        for(auto it:strs){
            string temp=it;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(it);
        }

        vector<vector<string>>ans;

        for(auto it:mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};


//HASHING

class Solution {
public:
    vector<int> hash(string &s){
        vector<int>v(256,0);
        for(int i=0;i<s.size();i++){
            v[s[i]]++;
        }

        return v;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>mp;

        for(auto it:strs){
            mp[hash(it)].push_back(it);
        }

        vector<vector<string>>ans;

        for(auto it:mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};