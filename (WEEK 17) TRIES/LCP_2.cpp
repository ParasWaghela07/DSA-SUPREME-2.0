class Solution {
public:
    class TrieNode{
        public:
        char value;
        TrieNode*childrens[10];

        TrieNode(char c){
            this->value=c;
            for(int i=0;i<10;i++){
                this->childrens[i]=NULL;
            }
        }
    };

    void insert(TrieNode*root,string&s,int index){
        if(index>=s.size()){
            return;
        }

        int charValue=s[index]-'0';
        if(!root->childrens[charValue]){
            TrieNode*temp=new TrieNode(s[index]);
            root->childrens[charValue]=temp;
        }

        insert(root->childrens[charValue],s,index+1);
    }

    int traverse(TrieNode*root,string&s,int index){
        if(index>=s.size()){
            return 0;
        }

        int ans=0;
        for(int i=0;i<10;i++){
            if(root->childrens[s[index]-'0']){
                ans=1+traverse(root->childrens[s[index]-'0'],s,index+1);
                break;
            }
        }

        return ans;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode*root=new TrieNode('-');
        for(auto it:arr1){
            string s=to_string(it);
            insert(root,s,0);
        }

        int ans=0;
        for(auto it:arr2){
            string s=to_string(it);
            ans=max(ans,traverse(root,s,0));
        }

        return ans;
    }
};