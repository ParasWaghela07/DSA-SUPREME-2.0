class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans;
        for(auto it:queries){
            string a=it;
            string p=pattern;
            bool isvalid=true;

            int i=0;
            int j=0;

            while(i<a.size() && j<p.size()){
                char c1=a[i];
                char c2=p[j];

                if(isupper(c1) && isupper(c2)){
                    if(c1==c2){
                        i++;
                        j++;
                    }
                    else{
                        isvalid=false;
                        break;
                    }
                }
                else if(isupper(c1) && islower(c2)){
                    isvalid=false;
                    break;
                }
                else if(islower(c1) && isupper(c2)){
                    i++;
                }
                else{
                    if(c1==c2){
                        i++;
                        j++;
                    }
                    else{
                        i++;
                    }
                }
            }

            while(i<a.size()){
                if(isupper(a[i])){
                    isvalid=false;
                    break;
                }
                i++;
            }

            if(j<p.size()) isvalid=false;

            if(isvalid)ans.push_back(true);
            else ans.push_back(false);

        }

        return ans;
    }
};



class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
       vector<bool>ans;
       for(int i=0;i<queries.size();i++){
           string s=queries[i];
           int k=0;
           bool capital=true;
           for(int j=0;j<s.size();j++){
               if(k==pattern.size() && isupper(s[j])){
                   capital=false;
               }
               if(k<pattern.size() && s[j]>='A' && s[j]<='Z' && s[j]!=pattern[k]){
                   capital=false;
                   break;
               }
               if(k<pattern.size() && s[j]==pattern[k]){
                   k++;
               }
           }

           if(k==pattern.size() && capital){
               ans.push_back(true);
           }
           else{
               ans.push_back(false);
           }
           
       } 

       return ans;
    }
};

//TRIE OWN 

class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode*children[58];

    TrieNode(char val){
        this->data=val;
        for(int i=0;i<58;++i){
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

        int index = word[i] - 'A';
        if(!root->children[index])
            root->children[index] = new TrieNode(word[i]);

        insertUtil(root->children[index], word, i + 1);
    }

    bool searchUtil(TrieNode*root, string&word, int i,string &p,int j){
        if(i >= word.size()){
            if(j>=p.size()) return true;
            else return false;
        }
            

        int index = word[i] - 'A';
        auto temp=root->children[index];
        char c=temp->data;
        if(isupper(c)){
            if(j<p.size() && c==p[j]){
                return searchUtil(temp,word,i+1,p,j+1);
            }
            else{
                return false;
            }
        }
        else{
            if(islower(p[j]) && p[j]==c) return searchUtil(temp,word,i+1,p,j+1);
            
            else return searchUtil(temp,word,i+1,p,j);
        }

        return false;
    }

    

public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        insertUtil(this->root, word, 0);
    }
    
    bool search(string word,string patt) {
        return searchUtil(this->root, word, 0,patt,0);
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
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans;
        Trie trie;
        for(auto it:queries){
            trie.insert(it);
        }
        for(auto it:queries){
            bool check = trie.search(it,pattern);
            if(check) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};


// TRIE LAKSHAY BHAIYA'S // SIMPLE AF 

class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode*children[58];

    TrieNode(char val){
        this->data=val;
        for(int i=0;i<58;++i){
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

        int index = word[i] - 'A';
        if(!root->children[index])
            root->children[index] = new TrieNode(word[i]);

        insertUtil(root->children[index], word, i + 1);
    }

    bool searchUtil(TrieNode*root, string&word, int i){
        if(i >= word.size())
            return root->isTerminal;

        int index = word[i] - 'A';
        if(root->children[index])
            return searchUtil(root->children[index], word, i + 1);
        else if(islower(word[i])){
            return searchUtil(root,word,i+1);
        }
        return false;
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
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans;
        Trie trie;
        trie.insert(pattern);

        for(auto it:queries){
            ans.push_back(trie.search(it));
        }
        return ans;
    }

};