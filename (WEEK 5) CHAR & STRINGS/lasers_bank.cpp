class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int i=0;
        int prev=0;
        int next=0;
        int ans=0;

        for(i=0;i<bank.size();i++){
            string s=bank[i];
            for(auto it:s){
                if(it=='1'){
                    prev++;
                }
            }
            if(prev>0) break;
        }
        i++;
        while(i<bank.size()){
            string s=bank[i];
            for(auto it:s){
                if(it=='1'){
                    next++;
                }
            }

            if(next>0){
                ans+=prev*next;
                prev=next;
                next=0;
                i++;
            }
            else{
                i++;
            }
        }

        return ans;
    }
};



class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int i=0;
        int j=1;
        
        int laser=0;

        while(j<bank.size()){

            string s1=bank[i];
            string s2=bank[j];

            int count1=0;
            int count2=0;

            for(int curr=0;curr<s1.size();curr++){

                count1=count1+(s1[curr]-'0');
                count2=count2+(s2[curr]-'0');
            }
            if(count1==0){
                i++;
                j++;
            }
            else if(count2==0){
                j++;
            }
            else{
                laser+=count1*count2;
                i=j;
                j++;
            }
        }
        return laser;
    }
};


