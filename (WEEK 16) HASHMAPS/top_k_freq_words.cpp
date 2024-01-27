//MAX HEAP :- N + N SPACE

class Solution {
public:
class compare{
    public:
    bool operator()(auto a,auto b){
        if(a.second != b.second)
        return a.second < b.second;
        else
        return a.first > b.first;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        unordered_map<string,int>mp;
        for(auto it:words){
            mp[it]++;
        }

        priority_queue<pair<string,int>,vector<pair<string,int>>,compare>pq;

        for(auto it:mp){
            pq.push({it.first,it.second});
        }

        while(k--){
            auto top=pq.top(); pq.pop();
            ans.push_back(top.first);
        }

        return ans;
    }
};

//MIN HEAP N+K SPACE

class Solution {
public:
class compare{
    public:
    bool operator()(auto a,auto b){
       return a.second == b.second ? a.first<b.first : a.second > b.second;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        unordered_map<string,int>mp;
        for(auto it:words){
            mp[it]++;
        }

        priority_queue<pair<string,int>,vector<pair<string,int>>,compare>pq;
        
        for(auto it:mp){
            
            if(pq.size() < k){
                pq.push(it);
            }
            else if(pq.size() == k && it.second > pq.top().second){
                pq.pop();
                pq.push(it);
            }
            else if(pq.size()==k && it.second == pq.top().second && it.first < pq.top().first){
                pq.pop();
                pq.push(it);
            }
        }

        while(!pq.empty()){
            auto top=pq.top(); pq.pop();
            ans.push_back(top.first);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};


//LAKSHAY BHAIYA TRIE
 class compare{
    public:
    bool operator()(const auto &a,const auto &b){
        return a.first==b.first ? a < b : a.first > b.first;
    }
};

class TrieNode{
    public:
    char data;
    bool isTerminal;
    int freq;
    TrieNode*children[26];

    TrieNode(char val){
        this->data=val;
        for(int i=0;i<26;++i){
            children[i] = 0;
            freq=0;
        }
        this->isTerminal=false;
    }
};

class Trie {
    TrieNode*root;

    void insertUtil(TrieNode*root, string&word, int i){
        if(i >= word.size()){
            root->isTerminal = 1;
            root->freq++;
            return;
        }

        int index = word[i] - 'a';
        if(!root->children[index])
            root->children[index] = new TrieNode(word[i]);

        insertUtil(root->children[index], word, i + 1);
    }

    bool searchUtil(TrieNode*root, string&word, int i){
        if(i >= word.size())
            return root->isTerminal;

        int index = word[i] - 'a';
        if(root->children[index])
            return searchUtil(root->children[index], word, i + 1);

        return false;
    }

    bool startsWithUtil(TrieNode*root, string&word, int i){
        if(i >= word.size())
            return true; // prefix found;

        int index = word[i] - 'a';
        if(root->children[index])
            return startsWithUtil(root->children[index], word, i + 1);

        return false;
    }

    void traverseUtil(TrieNode* root,string &s,priority_queue<pair<int,string>,vector<pair<int,string>>,compare> &pq ,int &k){
        if(!root) return;
        if(root->isTerminal) {
            // cout<<s << " "<<root->freq<<endl;
            if(pq.size() < k){
                pq.push({root->freq,s});
            }
            else if(pq.size()==k && root->freq > pq.top().first){
                pq.pop();
                pq.push({root->freq,s});
            }
        }

        for(int i=0;i<26;i++){
            if(root->children[i]){
                s.push_back(i + 'a');
                traverseUtil(root->children[i],s,pq,k);
                s.pop_back();
            }
        }
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        insertUtil(this->root, word, 0);
    }
    
    bool search(string word) {
        return searchUtil(this->root, word, 0);
    }
    
    bool startsWith(string prefix) {
        return startsWithUtil(this->root, prefix, 0);
    }

    void traverse(priority_queue<pair<int,string>,vector<pair<int,string>>,compare> &pq,int &k){
        string s;
        traverseUtil(root,s,pq,k);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */



class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        Trie trie;
        vector<string>ans;
        for(auto it:words){ 
            trie.insert(it);
        }

        priority_queue<pair<int,string>,vector<pair<int,string>>,compare>pq;
        trie.traverse(pq,k);

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
 