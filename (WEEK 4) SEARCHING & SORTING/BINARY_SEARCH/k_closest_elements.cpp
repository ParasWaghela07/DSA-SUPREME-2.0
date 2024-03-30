class Solution {
public:
    //own   
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i=0;
        int j=k-1;

        int currDiff=abs(x-arr[i]);

        while(j<arr.size()-1){
            int nxt=arr[j+1];
            if(abs(nxt-x) < currDiff){
                j++;
                i++;
                currDiff=abs(arr[i]-x);
            }
            else if(abs(nxt-x)==currDiff && arr[i]==arr[j+1]){
                j++;
                i++;
            }
            else{
                break;
            }
        }

        vector<int>ans;
        for(int index=i;index<=j;index++){
            ans.push_back(arr[index]);
        }

        return ans;
    }
};


///////////////////////////////////
        int l=0;
        int h=arr.size()-1;

        while(h-l>=k){
            if(x-arr[l]>arr[h]-x){
                l++;
            }
            else{
                h--;
            }
        }
        return vector<int>(arr.begin()+l,arr.begin()+h+1);

//////////////////////////


int lowerbound(vector<int> &nums,int target){
    int s=0;
    int e=nums.size()-1;
    int m=s+(e-s)/2;
    int ans=e;

    while(s<=e){
        if(nums[m]>=target){
            ans=m;
            e=m-1;
        }
        else{
            s=m+1;
        }
        
        m=s+(e-s)/2;
    }
    return ans;
}
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        int h=lowerbound(arr,x);
        cout<<h<<endl;
        int l=h-1;

        while(k--){
            if(l<0){
                h++;
            }
            else if(h>=arr.size()){
                l--;
            }
            else if(x-arr[l]>arr[h]-x){
                h++;
            }
            else{
                l--;
            }
        }
        
        return vector<int>(arr.begin()+l+1,arr.begin()+h);