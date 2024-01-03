#include<bits/stdc++.h>
using namespace std;
//////////////////////// FAILEDDDDD ///////////////////////////////////////////////
class TrieNode{
    public:
    char ch;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char val){
        this->ch=val;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        this->isTerminal=false;
    }
};

void insert(TrieNode* root,string s){
    if(s.size()==0){
        root->isTerminal=true;
        return;
    }
    char ch=s[0];
    TrieNode* child;
    int index=ch-'a';

    if(root->children[index]!=NULL){
        child=root->children[index];
    }
    else{
        child=new TrieNode(ch);
        root->children[index] = child;
    }

    insert(child,s.substr(1));
}

bool search(TrieNode* root,string s){

    if(s.size()==0){
        return root->isTerminal;
    }

    char ch=s[0];
    int index=ch-'a';
    TrieNode* child;
    if(root->children[index]!=NULL){
        child=root->children[index];
    }
    else{
        return false;
    }

    return search(child,s.substr(1));

}

void deleteWord(TrieNode* root,string s){
     if(s.size()==0){
         root->isTerminal=false;
         return;
    }

    char ch=s[0];
    int index=ch-'a';
    TrieNode* child;
    if(root->children[index]!=NULL){
        child=root->children[index];
    }
    else{
        return ;
    }

     deleteWord(child,s.substr(1));
}

void printSuggestions(TrieNode* root,string prefix,string suffix,vector<string>&s){
    if(root->isTerminal){
        s.push_back(prefix+suffix);
    }
    for(int i=0;i<26;i++){
        if(root->children[i]!=NULL){
            printSuggestions(root->children[i],prefix,suffix+root->children[i]->ch,s);
        }
    }
}

void storeString(TrieNode* root, vector<string>& ans, string &input, string& prefix) {
  //base case
  if(root->isTerminal == true) {
    //ans store
    ans.push_back(prefix + input);
    //return ?
  }

  for(char ch='a'; ch<='z'; ch++) {
    int index = ch - 'a';
    TrieNode* next = root->children[index];
    if(next != NULL) {
      //child exist
      input.push_back(ch);
      //baaaki recursion
      storeString(next, ans, input, prefix);
      //backtrack
      input.pop_back();
    }
  }
}


void stringSuggestions(TrieNode* root,string s,vector<string>&sugg,string prefix){
    if(s.size()==0){
        TrieNode* last=root;
        printSuggestions(last,prefix,s,sugg);
    }
    char ch=s[0];
    int index=ch-'a';
    TrieNode* child;
    if(root->children[index]!=NULL){
        child=root->children[index];
    }
    else{
        return ;
    }

     stringSuggestions(child,s.substr(1),sugg,prefix);
}



int main(){
    TrieNode* root=new TrieNode('-');
    insert(root,"paras");
    insert(root,"param");
    insert(root,"saas");
    insert(root,"pras");
    insert(root,"veet");
    insert(root,"vt");
    insert(root,"heet");
    insert(root,"oeet");
    insert(root,"oat");

    // if(search(root,"paras")){
    //     cout<<"FOUND"<<endl;
    // }
    // else{
    //     cout<<"NOT-FOUND"<<endl;
    // }

    // deleteWord(root,"paras");
    // if(search(root,"paras")){
    //     cout<<"FOUND"<<endl;
    // }
    // else{
    //     cout<<"NOT-FOUND"<<endl;
    // }

    // vector<string>sugg;
    // stringSuggestions(root,"pa",sugg,"pa"); ----> string suggestion
    
    // for(int i=0;i<sugg.size();i++){
    //     cout<<sugg[i]<<endl;
    // }

    vector<vector<string>>s=AllCharStringSuggestions(root,"pov");
    for(int i=0;i<s.size();i++){
        for(auto it:s[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}