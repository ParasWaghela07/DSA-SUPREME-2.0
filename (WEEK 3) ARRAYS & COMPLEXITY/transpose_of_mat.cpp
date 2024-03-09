#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int n=3;
    int m=3;

    for(int i=0;i<n;i++){
        for(int j=i;j<m;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=0;i<n;i++){
            cout<<arr[i][m-i-1]<<" ";
    }


}