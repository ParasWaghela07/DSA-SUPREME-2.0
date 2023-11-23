#include<bits/stdc++.h>
using namespace std;


// int keypair(int arr[],int size, int key){

//     for(int i=0;i<size-1;i++){
//         if(arr[i]+arr[i+1]==key)
//         return 1;
//     }

//     return -1;

// }

// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int x;
//     cin>>x;

//     int decision=keypair(arr,n,x);                   //key pair

//     if(decision==1){
//         cout<<"YES"<<endl;
//     }
//     else{
//         cout<<"NO"<<endl;
//     }

// }


// int main(){
//     int arr[8]={2,2,2,2,2,2,2,2};          //sort first

//     for(int i=0;i<8;i++){
//         if(arr[i]!=i+1){
//             cout<<i+1<<" ";              //missing no from duplicates
//         }
//     }
//     }


// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     vector<int>ans(n,0);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//         ans[arr[i]]++;
//     }
//                                             //first repeating
//     for(int i=0;i<ans.size();i++){
//         if(ans[i]>1){
//             cout<<i<<endl;
//             break;
//         }
//     }
// }




// int main(){
//     int n1,n2,n3,temp=0;
//     cout<<"Enter sizes of 3"<<endl;
//     cin>>n1>>n2>>n3;
//     int a[n1],b[n2],c[n3];
//     cout<<"enter 1st array"<<endl;
//     for(int i=0;i<n1;i++){
//         cin>>a[i];
//     }
//     cout<<"enter 2nd array"<<endl;
//      for(int i=0;i<n2;i++){
//         cin>>b[i];
//     }
//     cout<<"enter 3rd array"<<endl;
//      for(int i=0;i<n3;i++){
//         cin>>c[i];
//     }
//                                               //commons in 3 sorted array
//     int i=0,j=0,k=0;
//     while(i<n1 && j<n2 && k<n3){
//         if(a[i]==b[j] && b[j]==c[k]){
//             if(a[i]!=temp){
//             cout<<a[i]<<" ";
//             temp=a[i];
//             }
//             i++;
//             j++;
//             k++;
//         }
//         else if(a[i]<b[j]){
//             i++;
//         }
//         else if(b[j]<c[k]){
//             j++;
//         }
//         else{
//             k++;
//         }
//     }
// }
