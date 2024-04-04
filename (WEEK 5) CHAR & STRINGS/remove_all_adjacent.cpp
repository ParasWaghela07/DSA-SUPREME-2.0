string removeDuplicates(string s) {
        string ans="";
        int index=0
        ;

        while(index<s.size()){
            if(ans.size()>0 && s[index]==ans[ans.size()-1]){
                ans.pop_back();
            }
            else{
                ans.push_back(s[index]);
            }
            index++;
        }
        return ans;
}