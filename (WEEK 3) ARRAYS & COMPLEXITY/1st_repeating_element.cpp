#include<bits/stdc++.h>
using namespace std;

int firstRepeated(int arr[], int n) {
        for(int i=0;i<n;i++){
            int index=abs(arr[i]%n);
            if(arr[index]<0){
                return index;
            }
            else{
                arr[index]*=-1;
            }
        }
        
        return -1;
    }

int main(){
    int arr[]={1,5,3,5,3,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=firstRepeated(arr,n);
    for(int i=0;i<n;i++){
        if(arr[i]<0) arr[i]*=-1;
    }
    cout<<ans<<endl;

}