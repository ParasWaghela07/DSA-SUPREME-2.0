
class Solution {
public:

class TrieNode{
    public:
    char ch;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char val){
        this->ch=val;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        this->isTerminal=false;
        this->childCount=0;
    }
};

void insert(TrieNode* root,string s){
    if(s.size()==0){
        root->isTerminal=true;
        return;
    }

    char ch=s[0];
    int index=ch-'a';
    TrieNode* child;
    if(root->children[index]!=NULL){
        child=root->children[index];
    }
    else{
        child=new TrieNode(ch);
        root->children[index]=child;
        root->childCount++;
    }

    insert(child,s.substr(1));
}

void findLCP(TrieNode* root,string &ans){
    if(root->isTerminal){
        return;
    }
    TrieNode* child;
    if(root->childCount==1){
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL){
                child=root->children[i];
            }
        }
        ans.push_back(child->ch);
    }
    else{
        return;
    }

    findLCP(child,ans);
}


    string longestCommonPrefix(vector<string>& strs) {

        TrieNode* root=new TrieNode('-');
        for(auto it:strs){
            insert(root,it);
        }
        string ans="";
        findLCP(root,ans);

        return ans;

    }
};




// WITHOUT TRIE

// string ans="";
        // string first=strs[0];
        // int index=-1;

        // for(int i=0;i<first.size();i++){
        //     index++;
        //     for(int j=1;j<strs.size();j++){
        //         string temp=strs[j];

        //         if(first[index]!=temp[index]){
        //             return ans;
        //         }

        //     }
        //     ans.push_back(first[index]);
        // }

        // return ans;

        // sort(strs.begin(),strs.end());
        // int a=strs.size();
        // string n=strs[0],m=strs[a-1],ans="";
        // for(int i=0;i<n.size();i++){
        //     if(n[i]==m[i]){ans+=n[i];}
        //     else break;
        // }
        // return ans;