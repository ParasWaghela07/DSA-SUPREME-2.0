class Solution {
public:
        --LEETCODE 769---

    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int toGo=arr[i];
            int index=i;
            while(index<arr.size() && index!=toGo){
                index++;
                if(arr[index]>toGo) toGo=arr[index];
            }
            i=index;
            ans++;
        }

        -----------------------------------

        int ans=0;
        int sum=0;

        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            int expSum=i*(i+1)/2;

            if(expSum==sum) ans++;
        }

        return ans;

        -----------------

        vector<int>prefix=arr;
        vector<int>suffix=arr;


        for(int i=1;i<arr.size();i++){
            prefix[i]=max(prefix[i],prefix[i-1]);
        }

        for(int i=arr.size()-2;i>=0;i--){
            suffix[i]=min(suffix[i+1],suffix[i]);
        }

        int ans=0;
        for(int i=0;i<arr.size();i++){
            int prevMax= i>0 ? prefix[i-1] : -1;
            int nextMin=suffix[i];

            if(prevMax<nextMin) ans++;
        }

        return ans;
    }
};