bool isSafe(int c[],int mid,int p){       // 1 2 3 4 , 110
    
    for(int i=0;i<c.size();i++){
        
        int cval=c[i];
        int temp=2;
        while(cval<mid && p>0) {
            cval+=c[i]*temp;
            temp++;
            p--;
        }

        if(p==0) return true;

    }

    return false;
}

int prata(int cook[],int prata){
    int s=0;
    int maxi=maximum element in cook __ARRAY
    

    int e= maxi*(prata*(prata+1)/2);

    while(s<=e){
        int mid=s+(e-s)/2;
        int ans=0;
        if(isSafe(cook,prata,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }

    return ans;
}