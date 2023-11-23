#include<bits/stdc++.h>
using namespace std;

int firstOcc(int arr[],int size,int target){

    int s=0;
    int e=size-1;
    int m=s+(e-s)/2;
    int index;
    while(s<=e){
        if(arr[m]==target){
            index=m;
            e=m-1;
        }
        else if(m<target){
            s=m+1;
        }
        else{
            e=m-1;
        }
        m=s+(e-s)/2;
    }
    return index;
}








int lastOcc(int arr[],int size,int target){
    

    int s=0;
    int e=size-1;
    int m=s+(e-s)/2;
    int index=-1;
    while(s<=e){
        if(arr[m]==target){
            index=m;
            s=m+1;
        }
        else if(m<target){
            s=m+1;
        }
        else{
            e=m-1;
        }
        m=s+(e-s)/2;
    }
    return index;
}





int totalOcc(int arr[], int size ,int target){
    return (lastOcc(arr,size,target)-firstOcc(arr,size,target)+1);
}










int missingEle(int arr[],int size){
    int s=0;
    int e=size-1;
    int m=s+(e-s)/2;
    int index=-1;

    int cat=abs(arr[0]-s);

    while(s<=e){
        if(abs(arr[m]-m)==cat){
            s=m+1;
        }
        else {
            index=m;
            e=m-1;
        }
        m=s+(e-s)/2;
    }
    return index + cat;
}
















int peakEle(int arr[],int size){
    int s=0;
    int e=size-1;
    int m=s+(e-s)/2;

    while (s<=e)
    {
        if((arr[m]>arr[m+1]) && (arr[m]>arr[m-1])){
            return arr[m];
        }
        else if(arr[m]<arr[m+1]){
            s=m+1;
        }
        else{
            e=m-1;
        }
        m=s+(e-s)/2;
    }
    return 0;
    
}









int findPivot(int arr[],int size){
    int s=0;
    int e = size-1;
    int m=s+(e-s)/2;

    while(s<=e){
        if(arr[m]>arr[m+1] && m+1<size){
            return m;
        }
        else if(arr[m]<arr[m-1] && m-1>=0){
            return m-1;
        }
        else if(arr[0]>arr[m]){
            s=m+1;
        }
        else{
            e=m-1;
        }
       m=s+(e-s)/2;
    }
    return -1;

}


int BinarySearch(int arr[],int size,int target,int s,int e){
    int m=s+(e-s)/2;

    while(s<=e){
        if(target==arr[m]){
            return m;
        }
        else if(target>arr[m]){
            s=m+1;
        }
        else{
            e=m-1;
        }
        m=s+(e-s)/2;
    }
    return -1;
}



int EleInRotatedArray(int arr[],int size,int target){
    int ans=-1;
    int pivot=findPivot(arr,size);

    if(target>=arr[0] && target<=arr[pivot]){
        ans=BinarySearch(arr,size,target,0,pivot);
    }
    else{
        ans=BinarySearch(arr,size,target,pivot+1,size-1);
    }
return ans;
}











int oddOcc(int arr[],int size){
    int s=0;
    int e=size-1;
    int m=s+(e-s)/2;

    while(s<=e){
        if(s==e){
            return arr[s];
        }
        else if((arr[m]==arr[m+1] && m%2==0 && m+1 <size) ){
            s=m+2;
        }
        else if((arr[m]==arr[m-1] && (m-1)%2==0 && m-1>=0)){
            s=m+1;
        }
        else if((arr[m]==arr[m+1] && m%2!=0 && m+1 <size)){
            e=m-1;
        }
        else if( (arr[m]==arr[m-1] && (m-1)%2!=0 && m-1>=0)){
            e=m-2;
        }
        else{
            return arr[m];
        }
        m=s+(e-s)/2;
        
    }
    return -1;
}











int divisionbyBS(int divS,int divD){
    int s=0;
    int e=divD;
    int mQ=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        
        if(mQ*divS==divD){
            return mQ;
        }
        else if(mQ*divS<divD){
            ans=mQ;
            s=mQ+1;
        }
        else{
            e=mQ-1;
        }
        mQ=s+(e-s)/2;
    }
    return ans;
}















bool isValid(int arr[],int n,int m, int mid){
    int st=1;
    int currentPages=0;

    for(int i=0;i<n;i++){
        if(currentPages+arr[i]<=mid){
        currentPages+=arr[i];
        }
        else {
            st++;
            currentPages=arr[i];
        }
        if(st>m){
            return false;
        }
    }
    return true;
}


int bookAllocation(int arr[],int n, int m){
    if(m>n){
        return -1;
    }

    int s=0;
    int e=accumulate(arr,arr+n,0); //sums all array elements//
    int ans=-1;
    while(s<=e){

        int mid=s+(e-s)/2;

        cout<<mid<<" ";

        if(isValid(arr,n,m,mid)==true){
            
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}






bool validHeight(int arr[],int n,int m,int target){
    int wood=0;

    for(int i=0;i<n;i++){
        if(arr[i]-target>0){
            wood=wood+(arr[i]-target);
        }
    }

    if(wood>=m){
        return true;
    }
    else{
        return false;
    }
}


int ekoSpoj(int arr[],int n, int m){
    int s=0;
    int e=accumulate(arr,arr+n,0);
    int ans=-1;

    while(s<=e){
        int mid=s+(e-s)/2;

        if(validHeight(arr,n,m,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}




bool isvalidTime(int cookrank[],int cooks,int prata,int mid){
    int noP=0;
    int timeTaken=0;

    for(int i=0;i<cooks;i++){
        int j=1;

        while(1){
            if((cookrank[i]*j)+timeTaken<=mid){
                noP++;
                timeTaken=timeTaken+(cookrank[i]*j);
                j++;
            }
            else{
                timeTaken=0;
                break;
            }
        }
        if(noP>=prata){
            return true;
        }
    }

    return false;


}




int prataSpoj(int cookrank[],int cooks,int prata){
    int s=0;
    int e=0;
    int ans=-1;
    for(int i=0;i<cooks;i++){
        if(cookrank[i]>e){
            e=cookrank[i];             //max value of cook rank or lazy cook
        }
    }

    e=e*(prata*(prata+1))/2;
    

    while(s<=e){
        int mid=s+(e-s)/2;

        if(isvalidTime(cookrank,cooks,prata,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}



int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // int target;
    // cout<<"TARGET :-"<<endl;
    // cin>>target;

    // cout<<firstOcc(arr,n,target)<<endl;

    // cout<<lastOcc(arr,n,target)<<endl;

    // cout<<totalOcc(arr,n,target)<<endl;

    // cout<<missingEle(arr,n)<<endl;

    // cout<<peakEle(arr,n)<<endl;

    // cout<<EleInRotatedArray(arr,n,target)<<endl;

    // cout<<oddOcc(arr,n)<<endl;

    // int divisor,dividend;

    // cin>>dividend>>divisor;
    
    // cout<<divisionbyBS(divisor,dividend)<<endl;

//book alloacation//
    int m;
    cin>>m; //no of students//

    // int ans=bookAllocation(arr,n,m);

    // int ans=ekoSpoj(arr,n,m);

    int ans=prataSpoj(arr,n,m);

    cout<<endl<<ans;

}