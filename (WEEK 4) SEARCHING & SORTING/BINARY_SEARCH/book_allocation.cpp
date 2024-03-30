 bool isSafe(int mid,int A[],int n,int m){
        int stu=m;
        int csum=0;
        int i=0;
        
        while(i<n){
            if(stu==0 || A[i]>mid){
                return false;
            }
            
            if(csum+A[i]>mid){
                stu--;
                csum=0;
            }
            else{
                csum+=A[i];
                i++;
            }
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        // sort(A,A+N);
        if(M>N){
            return -1;
        }
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=A[i];
        }
        
        int s=0;
        int e=sum;
        int ans=-1;
        
        while(s<=e){
            int mid=s+(e-s)/2;
            
            if(isSafe(mid,A,N,M)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        
        return ans;
    }