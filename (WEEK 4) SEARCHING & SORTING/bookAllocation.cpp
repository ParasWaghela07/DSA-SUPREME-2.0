class Solution 
{
    public:
    
    
    bool check(int arr[],int n,int m,int num){
        int stuNo=1;
        int stuVal=0;
        int i=0;
        while(i<n){
            
            if(stuNo>m){
                return false;
            }
            int currVal=arr[i];
            
            if(stuVal+currVal <= num){
                 stuVal+=currVal;
                 i++;
            }
           
            else{
                stuNo++;
                stuVal=0;
            }
            
        }
        
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M)
    
    {
        if(M>N){
            return -1;
        }
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
        }
        
        int start=0;
        int end=sum;
        int ans=-1;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(check(A,N,M,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        
        return ans;
    }
};