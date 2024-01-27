class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
       vector<bool>ans;
       for(int i=0;i<queries.size();i++){
           string s=queries[i];
           int k=0;
           bool capital=true;
           for(int j=0;j<s.size();j++){
               if(k==pattern.size() && isupper(s[j])){
                   capital=false;
               }
               if(k<pattern.size() && s[j]>='A' && s[j]<='Z' && s[j]!=pattern[k]){
                   capital=false;
                   break;
               }
               if(k<pattern.size() && s[j]==pattern[k]){
                   k++;
               }
           }

           if(k==pattern.size() && capital){
               ans.push_back(true);
           }
           else{
               ans.push_back(false);
           }
           
       } 

       return ans;
    }
};