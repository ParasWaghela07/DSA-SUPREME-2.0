#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char ch;
    bool isTerminal;
    TrieNode* children[26];

    TrieNode(char c){
        this->ch=c;
        isTerminal=false;
        for(int i=0;i<26;i++){
            this->children[i]=NULL;
        }
    }
};

void insert(TrieNode*root,string word,int index){
    if(index>=word.size()){
        root->isTerminal=true;
        return;
    }

    int charIndex=word[index]-'a';
    char character=word[index];

    if(root->children[charIndex]==NULL){
        TrieNode* newNode=new TrieNode(character);
        root->children[charIndex]=newNode;

        insert(root->children[charIndex],word,index+1);
    }
    else{
        insert(root->children[charIndex],word,index+1);
    }
}

bool search(TrieNode*root,string &word,int index){
    if(index>=word.size()){
        return root->isTerminal;
    }

    int charIndex=word[index]-'a';
    
    if(root->children[charIndex]==NULL){
        return false;
    }
    else{
        return search(root->children[charIndex],word,index+1);
    }
}

void remove(TrieNode*root,string &word,int index){
    if(index>=word.size()){
        root->isTerminal=false;
        return;
    }

    int charIndex=word[index]-'a';
    
    if(root->children[charIndex]==NULL){
        return;
    }
    else{
        return remove(root->children[charIndex],word,index+1);
    }
}
void getSuffix(TrieNode*root,string word,vector<string>&ans){

    if(root->isTerminal){
        ans.push_back(word);
    }
    
    for(int i=0;i<26;i++){
        if(root->children[i]!=NULL){
            word.push_back(root->children[i]->ch);
            getSuffix(root->children[i],word,ans);
            word.pop_back();
        }
    }
}

void suggestions(TrieNode*root,string &prefix,int index,vector<string>&ans){
    if(index>=prefix.size()){
        getSuffix(root,prefix,ans);
        return;
    }

    int charIndex=prefix[index]-'a';
    
    if(root->children[charIndex]==NULL){
        return;
    }
    else{
        suggestions(root->children[charIndex],prefix,index+1,ans);
    }
}

int main(){
    TrieNode* root=new TrieNode('-');
    insert(root,"car",0);
    insert(root,"cannon",0);
    insert(root,"dumb",0);
    insert(root,"door",0);
    insert(root,"doorlock",0);
    insert(root,"doom",0);
    insert(root,"plumber",0);

    cout<<"Insertion Done"<<endl;

    // string word="door";
    // if(search(root,word,0)){
    //     cout<<"FOUND"<<endl;
    // }
    // else{
    //     cout<<"NOT FOUND"<<endl;
    // }

    // remove(root,word,0);

    // if(search(root,word,0)){
    //     cout<<"FOUND"<<endl;
    // }
    // else{
    //     cout<<"NOT FOUND"<<endl;
    // }

    string prefix="doorl";
    string helper="";

    for(auto it:prefix){
        helper.push_back(it);
        vector<string>sugg;
        suggestions(root,helper,0,sugg);
    if(sugg.size()==0){
        cout<<"No words are found starting with given prefix"<<endl;
    }
    else{
        cout<<"Suggestions for prefix : "<<helper<<" are -> ";
        for(auto it:sugg){
        cout<<it<<",";
        }
    }
    cout<<endl<<endl;
    }
    

}