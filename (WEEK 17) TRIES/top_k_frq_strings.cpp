class Solution {
public:
 class compare{
    public:
    bool operator()(const pair<string,int>&a,const pair<string,int>&b){
        if(a.second==b.second) return a.first < b.first;
        else return a.second > b.second;
    }
 };
    class TrieNode{
        public:
        char ch;
        bool isTerminal;
        TrieNode* childrens[26];
        int frq;

        TrieNode(char ch){
            this->ch=ch;
            this->isTerminal=false;
            this->frq=0;
            for(int i=0;i<26;i++){
                this->childrens[i]=0;
            }
        }
    };

    void insert(TrieNode*root,string &word,int index){
        if(index>=word.size()){
            root->isTerminal=true;
            root->frq++;
            return;
        }

        char chIndex=word[index]-'a';
        if(!root->childrens[chIndex]) 
            root->childrens[chIndex]=new TrieNode(word[index]);

        insert(root->childrens[chIndex],word,index+1);
        
    }

    void traverse(TrieNode*root,string &s,priority_queue<pair<string,int>,vector<pair<string,int>>,compare>&pq,int &k){
        if(root->isTerminal){
            if(pq.size() < k){
                pq.push({s,root->frq});
            }
            else if(pq.size()==k && root->frq > pq.top().second){
                pq.pop();
                pq.push({s,root->frq});
            }
        }

        for(int i=0;i<26;i++){
            if(root->childrens[i]){
                s.push_back(root->childrens[i]->ch);
                traverse(root->childrens[i],s,pq,k);
                s.pop_back();
            }
        }
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        TrieNode*root=new TrieNode('-');
        for(auto it:words){
            insert(root,it,0);
        }
        priority_queue<pair<string,int>,vector<pair<string,int>>,compare>pq;
        string s="";
        traverse(root,s,pq,k);

        vector<string>ans;
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;

    }
};