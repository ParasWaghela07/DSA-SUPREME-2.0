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

void printStrings(TrieNode* root, string s, string op) {
    if (root == NULL) {
        return;
    }

    if (root->isTerminal) {
        cout << s + op << endl;
    }

    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            printStrings(root->children[i], s, op + root->children[i]->ch);
        }
    }
}

void AllStrings(TrieNode* root, string s, int &i) {
    if (s.size() <= i) {
        string op = "";
        printStrings(root, s, op);
        return;
    }

    TrieNode* child;
    int idx = s[i] - 'a'; // Convert character to array index
    if (root->children[idx] != NULL) {
        child = root->children[idx];
        i++;
        AllStrings(child, s, i);
    } else {
        return;
    }
}

int main()
{
    TrieNode *root = new TrieNode('-');
    string input1 = "paras";
    int index1 = 0;
    Insertion(root, input1, index1);

    string input2 = "parse";
    int index2 = 0;
    Insertion(root, input2, index2);

    string input3 = "prem";
    int index3 = 0;
    Insertion(root, input3, index3);

    int temp=0;
    AllStrings(root,"pars",temp);
    
    

}