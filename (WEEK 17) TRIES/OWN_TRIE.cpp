#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char ch;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char val)
    {
        this->ch = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

void Insertion(TrieNode *root, string s, int &i)
{
    // cout << root->ch << " : " << root->isTerminal << endl;
    if (i >= s.size())
    {
        root->isTerminal = true;
        // cout << root->ch << " : " << root->isTerminal << endl;
        return;
    }

    char currentChar = s[i];     // Retrieve the character at index i
    int idx = currentChar - 'a'; // Convert character to array index
    TrieNode *child;
    if (root->children[idx] != NULL)
    {
        child = root->children[idx];
    }
    else
    {
        child = new TrieNode(currentChar);
        root->children[idx] = child;
    }
    i++;
    Insertion(child, s, i);
}

bool Search(TrieNode *root, string s, int &i)
{
    // cout << root->ch << " : " << root->isTerminal << endl;
    if (i >= s.size())
    {
        return root->isTerminal; // Check if the current node marks the end of a valid word
    }

    TrieNode *child;
    int idx = s[i] - 'a'; // Convert character to array index
    if (root->children[idx] != NULL)
    {
        child = root->children[idx];
        i++;
        return Search(child, s, i);
    }
    else
    {
        return false; // Return false if the character doesn't exist in the Trie
    }
}

void deleteWord(TrieNode* root,string s,int &i){
     if (i >= s.size())
    {
        root->isTerminal=false;
        return ; 
    }

    TrieNode *child;
    int idx = s[i] - 'a'; // Convert character to array index
    if (root->children[idx] != NULL)
    {
        child = root->children[idx];
        i++;
        deleteWord(child,s,i);
    }
    else
    {
        return; 
    }
}

int main()
{
    TrieNode *root = new TrieNode('-');
    string input1 = "paras";
    int index1 = 0;
    Insertion(root, input1, index1);

    // string input2 = "parse";
    // int index2 = 0;
    // Insertion(root, input2, index2);

    // string input3 = "heet";
    // int index3 = 0;
    // Insertion(root, input3, index3);

    int searchIndex = 0;
    if (Search(root, "paras", searchIndex))
    {
        cout << "FOUND" << endl;
    }
    else
    {
        cout << "NOT FOUND" << endl;
    }
    
    int delIndex=0;
    deleteWord(root,"paras",delIndex);

    int searchIndex2 = 0;
    if (Search(root, "paras", searchIndex2))
    {
        cout << "FOUND" << endl;
    }
    else
    {
        cout << "NOT FOUND" << endl;
    }

}