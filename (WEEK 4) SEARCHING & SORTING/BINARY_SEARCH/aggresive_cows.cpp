#define ll long long
class Solution {
public:

    bool isSafe(vector<int>&stalls,int cow,int mid){
        int curr=1;
        int i=1;
        int prev=stalls[0];
       
        while(i<stalls.size()){
           
            if(stalls[i]-prev >=mid){
                curr++;
                prev=stalls[i];
                i++;
            }
            else{
                i++;
            }
             if(curr==cow){
                return true;
            }
           
           
        }
       
        // cout<<mid<<endl;
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        ll sum=0;
        for(int i=0;i<stalls.size();i++){
            sum+=stalls[i];
        }
       
        ll s=0;
        ll e=sum;
       
        ll ans=-1;
             ll mid=s+(e-s)/2;
       
        while(s<=e){
            // cout<<mid<<endl;
            if(isSafe(stalls,k,mid)){
                // cout<<mid<<endl;
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
       
        return ans;
    }
