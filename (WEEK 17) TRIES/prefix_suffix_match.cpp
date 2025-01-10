//Approach-1 Brute Force
//T.C : O(n^2 * l)
//S.C : O(n^2 * l)
    //lc-3042
class Solution {
public:
    
    bool isPrefixAndSuffix(string &check, string &s) {
        int n = check.length();

        //You can use fine() function as well
        string s1 = s.substr(0, n);
        string s2 = s.substr(s.length() - n, n);
        
        return s1 == check && s2 == check;
        
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        auto lambda = [](string& s1, string& s2) {
            return s1.length() < s2.length();
        };
        
        //sort(begin(words), end(words), lambda);
        
        int count = 0;
        for(int i = 0; i < words.size()-1; i++) {
            for(int j = i+1; j < words.size(); j++) {
                if(words[i].length() <= words[j].length() && isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        
        return count;
    }
};

//Approach-2 - Using TRIE 
//T.C : ~O(n^2*l), n = number of words, l = average length of each word
//S.C : ~O(n*l), need to store all characters of words
struct trieNode {
    trieNode* children[26];
    bool isEndOfWord;
};

trieNode* getNode() {
    trieNode* newNode = new trieNode();
    newNode->isEndOfWord = false;
    for(int i = 0; i < 26; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

class Trie {
    public:
        trieNode* root;

        Trie() {
            root = getNode();
        }

        void insert(string word) {
            trieNode* pCrawl = root;
            for(int i = 0; i < word.length(); i++) {
                int idx = word[i] - 'a';
                if(pCrawl->children[idx] == NULL) {
                    pCrawl->children[idx] = getNode();
                }
                pCrawl = pCrawl->children[idx];
            }
            pCrawl->isEndOfWord = true;
        }

        bool searchPrefix(string prefix) {
            trieNode* pCrawl = root;
            for(int i = 0; i < prefix.length(); i++) {
                int idx = prefix[i] - 'a';
                if(pCrawl->children[idx] == NULL) {
                    return false;
                }
                pCrawl = pCrawl->children[idx];
            }

            return true;
        }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();

        int count = 0;

        for(int j = 0; j < n; j++) {
            Trie prefixTrie; //calls constrctor
            Trie suffixTrie; //calls constructor

            prefixTrie.insert(words[j]);        
            string reversed = words[j];
            reverse(begin(reversed), end(reversed));

            suffixTrie.insert(reversed);

            for(int i = 0; i < j; i++) {
                if(words[i].length() > words[j].length()) {
                    continue;
                }

                string rev = words[i];
                reverse(begin(rev), end(rev));

                if(prefixTrie.searchPrefix(words[i]) == true && suffixTrie.searchPrefix(rev) == true) {
                    count++;
                }
            }
        }

        return count;
    }
};
---//MINE
class Solution {
public:
    bool isValid(string &a,string &b){
        if(a.size()>b.size()) return false;
        int i=0;
        int j=b.size()-1;
        
        for(int index=0;index<a.size();index++){
            if(a[index]!=b[i] || a[a.size()-index-1]!=b[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(isValid(words[i],words[j])) ans++;
            }
        }

        return ans;
    }
};

//
class Solution {
public:
    class TrieNode{
        public:
        char val;
        TrieNode* childrens[26];
        bool isTerminal;

        TrieNode(char ch){
            this->val=ch;
            this->isTerminal=false;
            for(int i=0;i<26;i++) this->childrens[i]=NULL;
        }
    };

    void insert(TrieNode*root,string s,int index){
        if(index>=s.size()){
            root->isTerminal=true;
            return;
        }

        int charIndex=s[index]-'a';
        if(!root->childrens[charIndex]){
            root->childrens[charIndex]=new TrieNode(s[index]);
        }

        insert(root->childrens[charIndex],s,index+1);
    }

    bool isPrefix(TrieNode*root,string s,int index){
        if(index>=s.size()) return true;

        int charIndex=s[index]-'a';
        if(!root->childrens[charIndex]) return false;
        else return isPrefix(root->childrens[charIndex],s,index+1);
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;

        for(int i=0;i<words.size();i++){
            TrieNode*prefix=new TrieNode('-');
            TrieNode*suffix=new TrieNode('-');

            insert(prefix,words[i],0);
            string rev=words[i];
            reverse(rev.begin(),rev.end());
            insert(suffix,rev,0);

            for(int j=0;j<i;j++){
                if(words[j].size()>words[i].size()) continue;
                string suf=words[j];
                reverse(suf.begin(),suf.end());

                if(isPrefix(prefix,words[j],0) && isPrefix(suffix,suf,0)) ans++;
            }
        }

        return ans;
    }
};