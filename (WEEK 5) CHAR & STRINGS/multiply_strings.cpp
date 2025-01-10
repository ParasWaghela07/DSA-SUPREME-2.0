class Solution {
public:
    string addStrings(string &a,string &b){
        string ans;

        int carry=0;
        int i=a.size()-1;
        int j=b.size()-1;

        while(i>=0 || j>=0 || carry>0){
            int d1=i>=0 ? a[i]-'0' :0;
            int d2=j>=0 ? b[j]-'0' :0;

            int sum=d1+d2+carry;
            int digit=sum%10;
            carry=sum/10;

            ans.push_back(digit+'0');
            if(i>=0)i--;
            if(j>=0)j--;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
    string multiply(string num1, string num2) {
        
        string ans="0";
        int zeroes=0;

        for(int i=num2.size()-1;i>=0;i--){
            int carry=0;
            string temp;
            for(int j=num1.size()-1;j>=0;j--){
                int a=num2[i]-'0';
                int b=num1[j]-'0';

                int mul=(a*b)+carry;
                carry=mul/10;
                int digit=mul%10;

                temp.push_back(digit+'0');
            }
            if(carry>0) temp.push_back(carry+'0');
            reverse(begin(temp),end(temp));
            for(int i=0;i<zeroes;i++) temp.push_back('0');
            zeroes++;

            cout<<temp<<endl;
            ans=addStrings(ans,temp);
        }

        return ans[0]=='0'?"0":ans;
    }
};