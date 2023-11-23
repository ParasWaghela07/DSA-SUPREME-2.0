#include <iostream>
#include<cmath>
#include <climits>
using namespace std;

// int main()
// {
//     int n, sum = 0, factor = 1,rem;
//     cin >> n;
//     while (n != 0)
//     {
//         rem = n % 2;                               //deimal to binary
//         sum = sum + ( rem * factor );
//         n = n / 2;
//         factor = 10 * factor;
//     }
//     cout << sum;
//     return 0;
// }




// int main(){
//     int b;
//     cin>>b;
//     int rem,i=0,dec=0;
//     while(b!=0){
//                                       //binary to decimal
//         rem=b%10;
//         dec=dec+(rem*pow(2,i));
//         b=b/10;
//         i++;
//     }

//     cout<<"Decimal no is= "<<dec<<endl;
// }



// int main(){
//     int n, flag=1;
//     cin>>n;
//     for(int i=2;i<=n;i++){
//         flag = 1;
//         for(int j=2;j<=i/2;j++){
//             if(i%j==0){
//                 flag = 0;
//             }
//         }                                        //prime no. from 2 to N
//         if(flag==1){
//             cout<<i<<endl;
//         }
//     }
//     return 0;
// }














// int main() {
// 	int n,a=0;
// 	cin>>n;
//     int z = n,digits=0;
//     while(z!=0){
//         z = z/10;
//         digits++;
//     }
//     while(n!=0){
//         int k = n%10,z=digits-1;
//         while(z--){                                      //reverse integer
//             k = k*10;
//         }
//         a = a + k;
//         digits--;
//         n = n/10;
//     }
//     cout<<a;
//     return 0;
// }







// bool checkMember(int n){
//     int f1 = 1, f2 = 1;
//     if(n==0 || n==1){
//         return true;
//     }
//     else{
//         while(1){
//             int temp = f1 + f2;
//             f1 = f2;
//             f2 = temp;
//             if(temp==n){                    //check fibo member
//                 return true;
//             }
//             else if(temp>n){
//                 return false;
//             }
//         }
//     }

// }

// int main(){
//     int num;
//     cin>>num;

//     bool des=checkMember(num);

//     if(des==1) cout<<"YEs"<<endl;
//         else cout<<"no"<<endl;
// }










/*
Pattern for N = 4
   1
  212
 32123
4321234
*/


// int main(){
//     int n;
//     cin>>n;
//     int i=0,gaps = n-1;
//     while(i<n){
//         int k=0,gaps=n-1-i;
//         while(k<gaps){
//             cout<<" ";
//             k++;
//         }
//         int num = i+1;
//         while(num>0){
//             cout<<num;
//             num = num - 1;
//         }
//         k = 2;
//         while(k<=(i+1)){
//             cout<<k;
//             k++;
//         }
//         k =0;
//         while(k<gaps){
//             cout<<" ";
//             k++;
//         }
//         i++;
//         cout<<"\n";
//     }
// }




// int main(){
//     int n,flag=0;
//     cin>>n;

//     for(int i=0;i<n;i++){
//         for(int j=0;j<n-i-1;j++){
//             cout<<" ";
//         }
//         flag=0;
//         int x=i+1;
//         for(int k=0;k<(2*i)+1;k++){
//             if(x>1 && flag==0){
//                 cout<<x;                           same as above
//                 x--;
//             }
//             else{
//                 cout<<x;
//                 x++;
//                 flag=1;
//             }
//         }
//         cout<<endl;
//     }
// }











/*
Pattern for N = 5
1234554321
1234**4321
123****321
12******21
1********1
*/

// int main(){
//     int n;
//     cin>>n;

//     for(int i=0;i<n;i++){
//         for(int j=0;j<n-i;j++){
//             cout<<j+1;
//         }

//         for(int st=0;st<2*i;st++){
//             cout<<"*";
//         }

//         for(int k=0;k<n-i;k++){
//             cout<<n-i-k;
//         }
//         cout<<endl;
//     }
// }








// int main(){
//     int n;
//     cin>>n;
//     int arr[n];

//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     int max = INT_MIN;
//     for(int i=0;i<n;i++){
// 	    if(max<arr[i]){
// 	      max=arr[i];                       //second highest number in array
//       }
//      }

//      int second = INT_MIN;

//      for(int i=0;i<n;i++){
// 	     if(max>arr[i] && arr[i]>second){
// 	       second = arr[i];
//        }
//      }
//      cout<<second;
// 		 return 0;
// }




/*
Pattern for N = 4
4444
333
22
1
*/

// int main(){
//   int i,j,n;
//     cin>>n;
//     for(i=0;i<n;i++){
//         for(j=0;j<n-i;j++){
//             cout<<n-i;
//         }
//         cout<<endl;
//     }
// }