#include<bits/stdc++.h>
using namespace std;

    int findPeakElement(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;

        while(s<e){
            int mid=s+(e-s)/2;

            if(nums[mid]<nums[mid+1]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }

        return nums[s];
    }






int main(){
    vector<int>v={7,3,2};
    cout<<"Peak element : "<<findPeakElement(v)<<endl;
}