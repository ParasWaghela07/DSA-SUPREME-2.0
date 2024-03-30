#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<int>&nums,int mid,int m){
	int ttl=0;
	
	for(int i=0;i<nums.size();i++){
		if(nums[i]>mid){
			ttl+=nums[i]-mid;
		}
	}
	
	if(ttl>=m) return true;
	else return false;
}

int main() {
	int n;
	cin>>n;
	vector<int>nums(n);
	for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	
	int m;
	cin>>m;
	
	int maxi=INT_MIN;
	for(int i=0;i<n;i++){
		maxi=max(maxi,nums[i]);
	}
	
	int s=0;
	int e=maxi;
	int ans=-1;
	
	while(s<=e){
		int mid=s+(e-s)/2;
		
		if(isSafe(nums,mid,m)){
			ans=mid;
			s=mid+1; 
		}
		else{
			e=mid-1;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}