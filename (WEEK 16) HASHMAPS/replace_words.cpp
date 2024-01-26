//OWN
string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,string>mp;
        for(auto it:dictionary){
            mp[it]=it;
        }
        int i=0;
        int n=sentence.size();
        string ans,temp,found;
        while(i<n){

            if(sentence[i]!=' ')
            temp+=sentence[i];

            if(mp.find(temp)!=mp.end()){
                if(found.size()==0) found=mp[temp];
                else found=mp[temp].size()<found.size()?mp[temp]:found;
            }
            if(sentence[i]==' ' || i==n-1){
                if(found.size()>0){
                    ans+=found;
                    found="";
                    temp="";
                }
                else{
                    ans+=temp;
                    temp="";
                    found="";
                }
                if(i!=n-1) ans+=' ';
            }
            i++;
        }
        return ans;
    }

    //REFINED
    class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>mp;
        for(auto it:dictionary){
            mp.insert(it);
        }
        int i=0;
        int n=sentence.size();
        string ans,temp;
        while(i<n){
            if(sentence[i]==' '){
                ans+=temp + ' ';
                temp="";
                i++;
            }
            temp+=sentence[i];

            if(mp.find(temp)!=mp.end()){
                ans+=temp + ' ';
                temp="";

                while(i<n && sentence[i]!=' ') i++;
            }
            
            i++;
        }
        if(temp=="")
            ans.pop_back();
        else
            ans += temp;
        return ans;
    }
};

//LAKSHAY BHAIYA TRIE METHOD

class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode*children[26];

    TrieNode(char val){
        this->data=val;
        for(int i=0;i<26;++i){
            children[i] = 0;
        }
        this->isTerminal=false;
    }
};

class Trie {
    TrieNode*root;

    void insertUtil(TrieNode*root, string&word, int i){
        if(i >= word.size()){
            root->isTerminal = 1;
            return;
        }

        int index = word[i] - 'a';
        if(!root->children[index])
            root->children[index] = new TrieNode(word[i]);

        insertUtil(root->children[index], word, i + 1);
    }

    bool searchUtil(TrieNode*root, string&word, int &i){
        if(root->isTerminal) return true;

        if(i >= word.size())
            return root->isTerminal;

        int index = word[i++] - 'a';
        if(root->children[index])
            return searchUtil(root->children[index], word, i);

        return false;
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        insertUtil(this->root, word, 0);
    }
    
    int search(string word) {
        int i=0;
        bool gotIt=searchUtil(this->root, word, i);
        return gotIt?i:-1;
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
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        string ans;
        Trie trie;
        
        for(auto it:dictionary){
            trie.insert(it);
        }
        int start=0,end=0;
        while(end<sentence.size()){

            if(sentence[end]==' ' || end==sentence.size()-1){
                int len=end==sentence.size()-1?sentence.size():end-start;

                string word=sentence.substr(start,len);

                int trieMatchIndex=trie.search(word);
                ans+=trieMatchIndex==-1?word:word.substr(0,trieMatchIndex);
                if(sentence[end]==' ') ans+=' ';

                start=end+1;
            }

            end++;

        }

        return ans;
    }
};


