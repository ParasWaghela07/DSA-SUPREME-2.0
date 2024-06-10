class Solution {
public:
    void solve(vector<int>& prices , int &minprice,int &maxprofit,int i){
        if(i>=prices.size()){
            return;
        }
        if(prices[i] < minprice) minprice = prices[i];

        if(prices[i]-minprice > maxprofit) maxprofit=prices[i]-minprice;

        solve(prices,minprice,maxprofit,i+1);
    }
    int maxProfit(vector<int>& prices) {
        // int maxi=0;
        // for(int i=0;i<prices.size()-1;i++){
        //     int curr=prices[i];
        //     for(int j=i+1;j<prices.size();j++){
        //         if(prices[j] > curr ){
        //             maxi = max(maxi,prices[j]-curr);
        //         }
        //     }
        // }

        // return maxi;

        int minprice=INT_MAX;
        int maxprofit=INT_MIN;
        solve(prices,minprice,maxprofit,0);

        return maxprofit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>rightMax(n);
        
        rightMax[n-1]=0;
        int maxi=prices[n-1];
        for(int i=n-1;i>=0;i--){
            rightMax[i]=maxi;
            maxi=max(maxi,prices[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int buy=prices[i];
            int sell=rightMax[i];

            ans=max(ans,sell-buy);
        }

        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP=INT_MAX;
        int maxP=INT_MIN;

        for(int i=0;i<prices.size();i++){
            minP=min(minP,prices[i]);
            maxP=max(maxP,prices[i]-minP); 
        }

        return maxP;
    }
};