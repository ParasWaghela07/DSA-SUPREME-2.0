#include<bits/stdc++.h>
using namespace std;

// int search(vector<int>& nums, int target) {
// 		int l = 0, r = nums.size() - 1;
// 		while(l <= r){
// 			int mid = l + (r-l)/2;
// 			if(nums[mid] == target) return mid;
// 			else if(nums[l]<=nums[mid]){
// 				if(nums[l]<=target && target<nums[mid]) r = mid-1;
// 				else l = mid+1;
// 			}                                                                 //search in rotated array
// 			else{
// 				if(nums[mid]<target && target<=nums[r]) l = mid+1;
// 				else r = mid-1;
// 			}
// 		}
// 		return -1;
// 	}

// int main(){
//     vector<int>arr;
//     arr.push_back(4);
//     arr.push_back(5);
//     // arr.push_back(6);
//     arr.push_back(1);
//     arr.push_back(2);
//     arr.push_back(3);

//     int target;
//     cin>>target;
//     cout<<search(arr,target)<<endl;
// }






// int mySqrt(int x) {
// 	int ans=-1;
//         if (x == 0)
//             return x;
//         int first = 1, last = x;
//         while (first <= last) {
//             int mid = first + (last - first) / 2;
//             if (mid  == x / mid)
//                 return mid;
//             else if (mid > x / mid) {
//                 last = mid-1;                                 //square root
//             }
//             else {
//                 first = mid+1;
// 				ans=mid;
//             }
//         }
//         return ans;
//     }


// int main(){
// 	int n;
// 	cin>>n;

// 	cout<<mySqrt(n)<<endl;
// }


// int findMin(vector<int>& nums) {
//         int start = 0, end = nums.size()-1, ans = start;
//         while(nums[start] > nums[end]) {
//             int mid = (start + end) << 1;
//             if(nums[mid] <= nums[start] && nums[mid] <= nums[end]) 
//                 end = mid;
//             else if(nums[mid] >= nums[start] && nums[mid] >= nums[end])
//                 start = mid+1;          
//             else return nums[mid];
//             ans = start;
//         }
//         return nums[ans];
//     }                                                          //minimum in rotated array






// int findPeakElement(vector<int>& nums) {
//         int n = nums.size();
//         int low = 0;
//         int high = n-1;
//         int mid = low+(high-low)/2;
//         while(low < high){

              
//              if(mid+1 < n && mid-1>=0 && nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){          //peakelement
//                 return mid;
//              }                                
//             else if(mid+1<n && nums[mid] >= nums[mid+1]){
//                 high = mid;
//             }
//             else{
//                 low = mid+1;
//             }

//             mid = low+(high-low)/2;
//         }
//         return mid;
//     }


// int main(){
//     vector<int>nums;
//     // int n;
//     // cin>>n;
//     // for(int i=0;i<n;i++){
//     //     cin>>nums[i];
//     // }
//     nums.push_back(10);
//     nums.push_back(9);
//     nums.push_back(8);
//     nums.push_back(7);
//     nums.push_back(6);

//     // cout<<findMin(nums)<<endl;
//     int x=findPeakElement(nums);
//     cout<<nums[x]<<endl;

    
// }







// // void insertionsort(int arr[],int size){
// //     for(int i=1;i<size;i++){
// //         int j=i-1;
// //         int key=arr[i];

// //         while(j>=0 && arr[j]>key){                          //insertion sort
// //             arr[j+1]=arr[j];
// //             j--;
// //         }

// //         arr[j+1]=key;

// //     }
    
// }


// void selectionsort(int arr[], int size){

//     for(int i=0;i<size-1;i++){
//         int min=i;
//         for(int j=i+1;j<size;j++){
//             if(arr[j]<arr[min]){                      //selection sort
//                 min=j;
//             }
//         }
//         swap(arr[i],arr[min]);
//     }
// }


// int main(){
//     int n;
//     cin>>n;
//     int arr[n];

//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     // bubblesort(arr,n);
//     selectionsort(arr,n);
//     // insertionsort(arr,n);

//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }

// }

int binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid]==target){
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
                
            }
        }
        
        if (left >= 0 and nums[left] == target) {
            return left;
        } else {
            return -1;
        }
    }


int main(){
    vector<int>nums;
    
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);

    int target;
    cin>>target;

    cout<<binarySearch(nums,target)<<endl;


}








