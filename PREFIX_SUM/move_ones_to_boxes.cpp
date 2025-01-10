class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans(boxes.size(),0);
        
        int sum=0;
        int cumsum=0;
        for(int i=0;i<boxes.size();i++){
            ans[i]+=cumsum;
            sum+=boxes[i]-'0';
            cumsum+=sum;
        }

        sum=0;
        cumsum=0;
        for(int i=boxes.size()-1;i>=0;i--){
            ans[i]+=cumsum;
            sum+=boxes[i]-'0';
            cumsum+=sum;
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans(boxes.size(),0);
        int n=boxes.size();

        int sum=0;
        int ones=0;

        for(int i=boxes.size()-1;i>=0;i--){
            if(ones>0) ans[i]=sum-(i*ones);
            if(boxes[i]=='1'){
                sum+=i;
                ones++;
            }
        }
        sum=0;
        ones=0;
        for(int i=0;i<boxes.size();i++){
            if(ones>0) ans[i]+=sum-((n-i-1)*ones);
            if(boxes[i]=='1'){
                sum+=(n-i-1);
                ones++;
            }
        }

        return ans;
    }
};