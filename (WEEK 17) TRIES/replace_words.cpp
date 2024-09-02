//OWN
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>mp;

        for(auto it:dictionary){
            mp.insert(it);
        }

        string ans="";
        int index=0;
        string temp="";

        while(index<sentence.size()){

            if(sentence[index]==' '){
                ans+=temp+' ';
                temp="";
            }
            else if(mp.find(temp)!=mp.end()){
                ans+=temp;
                while(index<sentence.size() && sentence[index]!=' ') index++;

                if(index<sentence.size()){
                    ans.push_back(' ');
                }

                temp="";
            }
            else{
                temp.push_back(sentence[index]);
            }

            index++;
        }
        if(temp.size()>0) ans+=temp;
        return ans;
    }
};

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

//// SIMPLER
class Solution {
public:
    class TrieNode{
        public:
        char ch;
        bool isTerminal;
        TrieNode* childrens[26];

        TrieNode(char ch){
            this->ch=ch;
            this->isTerminal=false;

            for(int i=0;i<26;i++){
                this->childrens[i]=0;
            }
        }
    };

    void insert(TrieNode*root,string &word,int index){
        if(index>=word.size()){
            root->isTerminal=true;
            return;
        }

        char chIndex=word[index]-'a';
        if(!root->childrens[chIndex]) 
            root->childrens[chIndex]=new TrieNode(word[index]);

        insert(root->childrens[chIndex],word,index+1);
        
    }

    bool search(TrieNode*root,string &word,int index,string &matched){
        if(root->isTerminal){
            return true;
        }
        if(index>=word.size()) return root->isTerminal;
        
        char chIndex=word[index]-'a';
        if(root->childrens[chIndex]!=NULL){
            matched.push_back(word[index]);
            return search(root->childrens[chIndex],word,index+1,matched);
        }
        else{
            return false;
        }
    }


    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode*root=new TrieNode('-');
        for(auto it:dictionary){
            insert(root,it,0);
        }

        int index=0;
        string ans="";
        while(index<sentence.size()){
            string word="";
            string matched="";
            while(index<sentence.size() && sentence[index]!=' '){
                word.push_back(sentence[index]);
                index++;
            }

            if(search(root,word,0,matched)){
                ans+=matched+' ';
            }
            else{
                ans+=word+' ';
            }
            index++;
        }

        ans.pop_back();

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


