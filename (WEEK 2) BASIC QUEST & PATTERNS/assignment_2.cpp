#include<bits/stdc++.h>
using namespace std;

// double AOC (double r){
//     double x=22,y=7;
//     double pie=x/y;

//     return pie*r*r;
// }
//                                        //area of circle
// int main(){
//     double radius;
//     cin>>radius;

//     cout<<AOC(radius)<<endl;
// }
 





// int factorial(int n){
//     int f=1;

//     for(int i=1;i<=n;i++){
//         f*=i;
//     }
//                                         //factorial
//     return f;
// }

// int main(){
//     int num;
//     cin>>num;

//     cout<<factorial(num)<<endl;
// }




// int main(){
//     int n;
//     cin>>n;
//     int count=0;
// for(int i=2;i<=n;i++){
    
//     for(int j=2;j<i;j++){
//         if(i%j==0){
//             count++;
//         }
//     }
//                                                        //prime nums from 1 to N
//     if(count==0){
//         cout<<i<<" is prime"<<endl;
//     }

//     count=0;
// }
// }



// int main(){
//     int num;
//     cin>>num;

//     vector<int>arr;

//     while(num!=0){
//         arr.push_back(num%10);
//         num/=10;
//     }
//                                               //number to digits
//     int len=arr.size();

//     for(int i=0;i<len;i++){
//         cout<<arr[len-i-1]<<" ";
//     }
// }





// int main(){

// int num;


// int n;
// vector<int>arr;
// bool b=true;
// while(b==true){

//     cout<<"press 1 to insert a digit"<<endl<<"press 2 for stop"<<endl;
//     cin>>num;

// switch(num){

//     case 1:cout<<"Enter a digit="<<" ";
//     cin>>n;
//     arr.push_back(n);
//     break;

//     case 2: 
//     b=false;
//     break;
// }
//                                               //digit to number
// }

// int len=arr.size();
// int ans=0;

// for(int i=0;i<len;i++){

// ans=(ans*10)+arr[i];

// }

// cout<<"Your Number is : "<<ans<<endl;

// }




// int main(){
//     cout<<"Enter km :"<<" ";

//     double km;
//     cin>>km;
//                                                      //km to miles
//     cout<<"Miles : "<<km*0.62137<<endl;
// }




// int main(){
//     int n;
//     cin>>n;

//     if((n&1)==0)
//     cout<<"EVEN"<<endl;                             //odd even by bitwise
//     else
//     cout<<"ODD"<<endl;
// }


// int main(){
//     int num;
//     cin>>num;

//     int ans=0;                              //reverse integer
    
//     while(num!=0){
//         ans=ans*10+(num%10);
//         num=num/10;
//     }

//     cout<<ans;
// }

// int main(){
//     int n;
//     cin>>n;

//     int k;
//     cin>>k;


//     int value=(1<<k);

//     cout<<(n|value)<<endl;
// }

 


