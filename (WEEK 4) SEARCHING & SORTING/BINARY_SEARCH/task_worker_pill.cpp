class Solution {
    public:
        -lc-2071
        bool isValid(vector<int>& t, vector<int>& w, int &p, int &str,int &mid){
            multiset<int>mst(w.begin(),w.begin()+mid);
            int pills=0;
            for(int i=mid-1;i>=0;i--){
                auto it   = prev(mst.end());
                if(*it >= t[i]) {
                    mst.erase(it);
                } else if(pills>=p) {
                    return false;
                } else {
                    //find the weakest worker which can do this strong task using pills
                    auto weakestWorkerIt = mst.lower_bound(t[i] - str);
                    if(weakestWorkerIt == mst.end()) {
                        return false;
                    }
                    mst.erase(weakestWorkerIt);
                    pills++;
                }
            }
    
            return true;
        }
        int maxTaskAssign(vector<int>& t, vector<int>& w, int p, int str) {
            sort(t.begin(),t.end());
            sort(w.rbegin(),w.rend());
    
            int n=t.size();
            int m=w.size();
    
            int s=0;
            int e=min(n,m);
    
            int ans=0;
    
            while(s<=e){
                int mid=s+(e-s)/2;
    
                if(isValid(t,w,p,str,mid)){
                    ans=mid;
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
    
            return ans;
        }
    };