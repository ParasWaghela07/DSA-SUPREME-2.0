
class TrieNode{
    public:
    char data;
    int str_index;
    TrieNode*children[26];

    TrieNode(char val){
        this->data=val;
        for(int i=0;i<26;++i){
            children[i] = 0;
        }
        this->str_index=-1;
    }
};

class Trie {
    TrieNode*root;

    void insertUtil(TrieNode*root, string&word, int i,int &Stringindex){
        if(i >= word.size()){
            root->str_index = Stringindex;
            return;
        }

        int index = word[i] - 'a';
        if(!root->children[index])
            root->children[index] = new TrieNode(word[i]);

        insertUtil(root->children[index], word, i + 1,Stringindex);
    }

    

public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string &word,int &Stringindex) {
        insertUtil(this->root, word, 0,Stringindex );
    }

    bool isPalin(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void searchCase2(TrieNode* root,vector<int>&Mypalin,string s){
        if(root->str_index!=-1){
            if(isPalin(s,0,s.size()-1)){
                Mypalin.push_back(root->str_index);
            }
        }

        for(int i=0;i<26;i++){
            if(root->children[i]!=0){
                s.push_back(i+'a');
                searchCase2(root->children[i],Mypalin,s);
                s.pop_back();
            }
        }
    }

    void search(string &word,vector<int>&Mypalin) {
        TrieNode*curr=root;

        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';

            if(curr->str_index!=-1){ // Trie string is matched and finished , vector string is remaining so rest part of it should be palindrome
                if(isPalin(word,i,word.size()-1)){
                    Mypalin.push_back(curr->str_index);
                }
            }

            if(curr->children[index]){
                curr=curr->children[index];
            }
            else{
                return;
            }
        }

        //IF REACHED HERE , vector string is finished and matched but trie has more char's then do this
        //Check in trie remaining char's is palindrome is not
        searchCase2(curr,Mypalin,"");

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
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>ans;
        Trie trie;
        //Insert all strings in reverse order with their terminal containing their index reference of original array index 
        for(int i=0;i<words.size();i++){
            auto s=words[i];
            reverse(s.begin(),s.end());
            trie.insert(s,i);
        }
        //find palindromic pairs
        for(int i=0;i<words.size();i++){
            vector<int>myPalin;

            trie.search(words[i],myPalin);

            for(auto it:myPalin){
                if(it!=i){
                    ans.push_back({i,it});
                }
            }
        }

        return ans;

    }
};