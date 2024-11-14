
------LAKSHAY BHAIYA-----

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            auto front=q.front();
            q.pop();

            string currString=front.first;
            int currCount=front.second;

            if(currString==endWord) return currCount;

            for(int i=0;i<currString.size();i++){
                char og=currString[i];
                for(char c='a';c<='z';c++){
                    currString[i]=c;
                    if(st.find(currString)!=st.end()){
                        q.push({currString,currCount+1});
                        st.erase(currString);
                    }
                }
                currString[i]=og;
            }

        }

        return 0;
    }
};

--------MINE--------

class Solution {
public:
    int dfs(string &src, unordered_map<string,vector<string>>&mp,unordered_map<string,bool>&vis,string &end){
        if(src==end) return 0;
        vis[src]=true;
        int ans=INT_MAX;

        for(auto it:mp[src]){
            if(!vis[it]){
                int recAns=dfs(it,mp,vis,end);
                if(recAns!=INT_MAX) ans=min(ans,1+recAns);
            }
        }

        vis[src]=false;

        return ans;
    }

    int bfs(string &src, unordered_map<string,vector<string>>&mp,unordered_map<string,bool>&vis,string &end){
        queue<pair<string,int>>q;
        q.push({src,0});

        int ans=INT_MAX;

        while(!q.empty()){
            auto front=q.front();
            q.pop();

            string frontString=front.first;
            int count=front.second;

            vis[frontString]=true;

            for(auto it:mp[frontString]){
                if(vis[it]) continue; 

                if(it==end) ans=min(count+1,ans);
                else q.push({it,count+1});
            }
        }

        return ans;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>>mp;
        int n=beginWord.size();
        for(int i=0;i<wordList.size();i++){
            int diff=0;
            for(int j=0;j<n;j++){
                if(beginWord[j]!=wordList[i][j]) diff++;
            }

            if(diff==1 && beginWord!=wordList[i]) mp[beginWord].push_back(wordList[i]);
        }

        if(mp.find(beginWord)==mp.end()) return 0;

        for(int i=0;i<wordList.size();i++){
            for(int j=0;j<wordList.size();j++){
                if(i==j) continue;

                int diff=0;
                for(int k=0;k<n;k++){
                    if(wordList[i][k]!=wordList[j][k]) diff++;
                }

                if(diff==1) mp[wordList[i]].push_back(wordList[j]);
            }
        }

        
        vector<string>opt=mp[beginWord];
        unordered_map<string,bool>vis;

        int ans = bfs(beginWord,mp,vis,endWord);

        return ans!=INT_MAX ? ans+1 : 0 ;
    }
};