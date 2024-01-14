class Solution {
public:
int carry=0;
    void addstrs(string &s1,string &s2,int it1,int it2,string &ans){

        if(it1 < 0 && it2<0){
            if(carry){
                ans.push_back(carry+'0');
            }
            return;
        }
        int lastNum1=0,lastNum2=0;
        if(it1>=0) lastNum1=s1[it1]-'0';
    
        if(it2>=0)  lastNum2=s2[it2]-'0';
       
        int sum=carry + lastNum1 + lastNum2;
        carry=sum/10;
        ans.push_back(sum%10 + '0');

        addstrs(s1,s2,it1-1,it2-1,ans);
    }
    string addStrings(string num1, string num2) {

        string ans="";
        int i=num1.size()-1;
        int j=num2.size()-1;
        addstrs(num1,num2,i,j,ans);

        reverse(ans.begin(),ans.end());

        return ans;
    }
};