class Solution {
public:
    //lakshay bhaiya
    void prmt(vector<int>&temp,int &count,int i,int n){
        if(i>=n+1){
            count++;
            return;
        }

        for(int j=1;j<=n;j++){
            if(temp[j]==0 && (i%j==0||j%i==0)){
                temp[j]=i;
                prmt(temp,count,i+1,n);
                temp[j]=0;
            }
        }
    }
    //mine 
    void prmt(vector<int>&temp,int &count,int i,int n){
        if(i>=n+1){
            count++;
            return;
        }

        for(int j=1;j<=n;j++){
            if(temp[j]==0 && (i%j==0||j%i==0)){
                temp[j]++;
                prmt(temp,count,i+1,n);
                temp[j]--;
            }
        }
    }
    int countArrangement(int n) {
        vector<int>temp(n+1,0);
        int count=0;
        prmt(temp,count,1,n);
  
        return count;
    }
};