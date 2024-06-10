class Solution {
public:
    //lakshay bhaiya
    void prmt(vector<int>&temp,int &n,int num,int &count){
        if(num>n){
            count++;
            return;
        }

        for(int index=1;index<temp.size();index++){
            if(temp[index]==0 && (num%index==0 || index%num==0)){
                temp[index]=num;
                prmt(temp,n,num+1,count);
                temp[index]=0;
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