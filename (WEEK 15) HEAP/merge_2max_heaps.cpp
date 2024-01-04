class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(a[i]);
        }
        for(int i=0;i<m;i++){
            pq.push(b[i]);
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};
 /// ////////-------------------------------------------------------
 vector<int>ans;
        int i=0;
        int j=0;
        
        while(i<n && j<m){
            if(a[i] > b[j]){
                ans.push_back(a[i]);
                i++;
            }
            else{
                ans.push_back(b[j]);
                j++;
            }
        }
        while(i<n){
            ans.push_back(a[i]);
            i++;
        }
        while(j<m){
            ans.push_back(b[j]);
            j++;
        }
        return ans;
///////////////////////////////--------------------------------------------------------
void heapify(vector<int>&ans,int i,int n){
            int leftIndex=2*i + 1;
            int rightIndex=2*i + 2;
            int largestIndex=i;
            
            if(leftIndex<n && ans[leftIndex] > ans[largestIndex]){
                largestIndex=leftIndex;
            }
            if(rightIndex < n && ans[rightIndex] > ans[largestIndex]){
                largestIndex=rightIndex;
            }
            
            if(largestIndex == i){
                return;
            }
            else{
                swap(ans[i],ans[largestIndex]);
                i=largestIndex;
            }
            
            heapify(ans,i,n);
        }
        vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int>ans(a.begin(),a.end());
        ans.insert(ans.end(),b.begin(),b.end());
        
        for(int i=ans.size()-1;i>=0;i--){
            heapify(ans,i,ans.size());
        }
        
        return ans;
    }