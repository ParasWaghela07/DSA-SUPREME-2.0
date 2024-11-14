
    gfg -- ACCEPTED
    leetcode -- MLE

class Solution {
public:
     vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {

        vector<vector<string>>ans;
        queue<pair<vector<string>,int>>q;
        q.push({{beginWord},1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);

        int prevlevel=-1;
        vector<string>tobeRemoved;

        while(!q.empty()){
            auto front=q.front();
            q.pop();

            auto currSeq=front.first;
            string currString=currSeq[currSeq.size()-1];
            int currCount=front.second;

            if(currCount!=prevlevel){
                for(auto it:tobeRemoved)st.erase(it); 
                tobeRemoved.clear();
                prevlevel=currCount;
            }

            if(currString==endWord) ans.push_back(currSeq);

            for(int i=0;i<currString.size();i++){
                char og=currString[i];
                for(char c='a';c<='z';c++){
                    currString[i]=c;
                    if(st.find(currString)!=st.end()){
                        auto temp=currSeq;
                        temp.push_back(currString);

                        q.push({temp,currCount+1});
                        tobeRemoved.push_back(currString);
                    }
                }
                currString[i]=og;
            }

        }

        return ans;
    }
};


    ----MLE---

class Solution {
public:
    void makeAns(vector<vector<string>>&ans,unordered_map<string,string>&parent,string &end){
        vector<string>temp;
        string s=end;
        temp.push_back(s);

        while(parent.find(s)!=parent.end()){
            s=parent[s];
            temp.push_back(s);
        }

        if(ans.size()>0){
            if(ans.back().size() > temp.size())ans.pop_back();
            else if(ans.back().size() < temp.size()) return;
        }
        reverse(temp.begin(),temp.end());
        ans.push_back(temp);
    }

    void bfs(string &src, unordered_map<string,vector<string>>&mp,unordered_map<string,bool>&vis,string &end,vector<vector<string>>&ans){
        queue<string>q;
        q.push(src);

        unordered_map<string,string>parent;

        while(!q.empty()){
            string frontString=q.front();
            q.pop();

            for(auto it:mp[frontString]){
                if(vis[it]) continue; 

                parent[it]=frontString;
                if(it==end) makeAns(ans,parent,end);
                else {
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        int n=beginWord.size();
        for(int i=0;i<wordList.size();i++){
            int diff=0;
            for(int j=0;j<n;j++){
                if(beginWord[j]!=wordList[i][j]) diff++;
            }

            if(diff==1 && beginWord!=wordList[i]) mp[beginWord].push_back(wordList[i]);
        }

        if(mp.find(beginWord)==mp.end()) return ans;

        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==beginWord) continue;
            for(int j=0;j<wordList.size();j++){
                if(i==j) continue;

                int diff=0;
                for(int k=0;k<n;k++){
                    if(wordList[i][k]!=wordList[j][k]) diff++;
                }

                if(diff==1) mp[wordList[i]].push_back(wordList[j]);
            }
        }

        for(auto it:mp){
            cout<<it.first<<" : ";
            for(auto it2:it.second){
                cout<<it2<<",";
            }
            cout<<endl;
        }

        unordered_map<string,bool>vis;
        bfs(beginWord,mp,vis,endWord,ans);

        return ans;
    }
};