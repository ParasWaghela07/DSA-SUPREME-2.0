#include<bits/stdc++.h>
using namespace std;


//ORDERING CAN CHANGE OR CAN BE DONE USING EXTRA SPACE  
int main(){
    int arr[]={-23,-7,12,-10,11,40,-60};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int i=0;
    int j=0;

    while(j<n){
        if(arr[j]<0){
            swap(arr[i],arr[j]);
            i++;
            j++;
        }
        else{
            j++;
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}