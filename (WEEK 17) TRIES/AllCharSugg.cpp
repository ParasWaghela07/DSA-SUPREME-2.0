#include <iostream>
#include<vector>
using namespace std;

class TrieNode{
  public:
    char value;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char val) {
      this->value = val;
      for(int i=0; i<26; i++) {
        children[i] = NULL;
      }
      this->isTerminal = false;
    }
};
//insertion
void insert(TrieNode* root, string word) {
  //cout << "recieved word: " << word << " for insertion " << endl;
  //base case
  if(word.length() == 0) {
    root->isTerminal = true;
    return;
  }

  char ch = word[0];
  int index = ch - 'a';
  TrieNode* child;
  if(root->children[index] != NULL) {
    //present
      child = root->children[index];
  }
  else {
    //absent
     child = new TrieNode(ch);
     root->children[index] = child;
  }

  //recursion
  insert(child, word.substr(1));

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


vector<vector<string> > getSuggestions(TrieNode* root, string input) {

  vector<vector<string> > output;
  TrieNode* prev = root;
  string inputhelper = "";

  for(int i=0; i<input.length(); i++) {
    char lastchar = input[i];
    int index = lastchar - 'a';
    TrieNode* curr = prev->children[index];

    if(curr == NULL) {
      break;
    }
    else {
      vector<string> nicheKaAns;
      inputhelper.push_back(lastchar);
      string dummy = "";
      storeString(curr, nicheKaAns, inputhelper, dummy);
      output.push_back(nicheKaAns);
      //important
      prev = curr;
    }

  }
  return output;
}


//SIMPLER
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

int main() {
  TrieNode* root = new TrieNode('-');

    insert(root,"paras");
    insert(root,"param");
    insert(root,"saas");
    insert(root,"pras");
    insert(root,"veet");
    insert(root,"vt");
    insert(root,"heet");
    insert(root,"oeet");
    insert(root,"oat");

  vector<vector<string> > ans = getSuggestions(root, "pov");
  //printing ans
  for(int i=0; i<ans.size(); i++) {
    cout << i << " -> ";
    for(auto str: ans[i]) {
      cout << str <<", ";
    }cout << endl;
  }


  return 0;
}
