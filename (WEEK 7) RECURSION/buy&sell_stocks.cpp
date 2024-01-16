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