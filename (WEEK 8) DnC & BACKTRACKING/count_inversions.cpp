long merge(vector<int>&arr,vector<int>&temp,int s,int mid,int e){
    long c=0;
    int i=s;
    int j=mid+1;
    int k=s;
    while(i<=mid && j<=e){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{ //inversion case
            temp[k++]=arr[j++];
            c+=mid-i+1;
        }
    }
    
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=e){
        temp[k++]=arr[j++];
    }
    
    while(s<=e){
        arr[s]=temp[s];
        s++;
    }
    return c;
    
}
long mergeSort(vector<int>&arr,vector<int>&temp,int s,int e){
    if(s>=e){
        return 0;
    }
    long c=0;
    int mid=(s+e)/2;
    c+=mergeSort(arr,temp,s,mid);
    c+=mergeSort(arr,temp,mid+1,e);
    c+=merge(arr,temp,s,mid,e);
    
    return c;
}
long countInversions(vector<int> arr) {
   long c=0;
   vector<int>temp(arr.size(),0);
   c=mergeSort(arr,temp,0,arr.size()-1);
   return c;
}