vector<int> factorial(int N){
        vector<int>ans;
        ans.push_back(1);
        int num=2;
        int carry=0;
        
        while(num<=N){
            for(int i=0;i<ans.size();i++){
                int calcu=(ans[i]*num) + carry;
                int digit=calcu%10;
                carry=calcu/10;
                
                ans[i]=digit;
                
            }
            while(carry){
                ans.push_back(carry%10);
                carry=carry/10;
            }
            carry=0;
            num++;
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }