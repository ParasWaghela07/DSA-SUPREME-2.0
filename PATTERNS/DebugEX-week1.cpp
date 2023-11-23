// #include<iostream>
// using namespace std;

// int main() {
// 	char c;
//     cin>>c;
//     if('a'<=c && c<= 'z'){
//         cout<<0;
//     }                                         check whether given char is capital , small or something else 
// 	else if('A'<=c && c<= 'Z'){
//         cout<<1;
//     }
//     else{
//         cout<<-1;
//     }
// }


// /*
// Pattern
// 1
// 23
// 345
// 4567
// */
// #include<iostream>
// using namespace std;

// /*
// Pattern
// 1
// 23
// 345
// 4567
// */

// int main(){
//     int n;
//     cin>>n;
//     int i=1;
//     while(i<n){
//         int j = i,count = 0;
//         while(count<i){                                  
//             cout<<j;
//             j = j + 1;
//             count = count + 1;
//         }
//         cout<<"\n";
//         i = i + 1;
//     }
// }


/*
Pattern
N = 4
   *
  ***
 *****
*******
*/
/*
Pattern
N = 4
   *
  ***
 *****
*******
*/
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int i=0;
//     while(i<n){
//         int j = i,count = 2*n+1,gaps=(n-i-1),k=0;
//         while(k<gaps){
//             cout<<" ";
//             k = k + 1;
//         }
//         int m = 1,ch = count - 2*gaps-1;
//         while(m<ch){
//             cout<<"*";
//             m = m + 1;
//         }
//         // k = 1;
//         // while(k<gaps){
//         //     cout<<" ";
//         //     k = k + 1;
//         // }
//         cout<<"\n";
//         i = i + 1;
//     }
// }









/*
Pattern
N = 4
1
22
333
4444
*/
// #include<iostream>
// using namespace std;
                                                   
// int main(){
//   int i,j,n;
//     cin>>n;
//     for(i=1;i<=n;i++){
//         for(j=1;j<i+1;j++){
// 	        cout<<i;
//         }
//     cout<<endl;
//     }
// }



/*
Pattern
N = 4
1
21
321
4321
*/
// #include<iostream>
// using namespace std;

// int main(){
//   int i,j,n;
//     cin>>n;
//     for(i=1;i<=n;i++){
//        int p=i;
//         for(j=1;j<=i;j++){
//           cout<<p;
//           p--;
//         }
//         cout<<endl;
        
//     }
// }


/*
Pattern
N = 5
E
DE
CDE
BCDE
ABCDE
*/
// #include<iostream>
// using namespace std;

// int main() {
//     int i,j,n;;
//     cin>>n;
//     for(i=0;i<n;i++){
//         char p='E'- i;
//         for(j=0;j<=i;j++){
//             cout<<p;
//             p++;  
//         }
//         cout<<endl;
//     }
// }



/*
Pattern
N = 4
   1
  232
 34543
4567654
*/
// #include<iostream>
// using namespace std;
// int main(){
//     int no;
//     cin>>no;
//     int i=1;
//     int n = no;
//     while(i<=(no)){
//         int gaps = n-i,k=1;
//         int j = i;

//         while(k<=gaps){
//             cout<<" ";
//             k = k + 1;
//         }


//         int ch = n - gaps + 1, z = ch-1;
//         while(z>=1){
//             cout<<j;
//             j = j + 1;
//             z = z - 1;
//         }

//         j = j - 1;
//         z = (ch-2);


//         while(z>=1){
//             j = j - 1;
//             cout<<j;
//             z = z - 1;
//         }
        
//         cout<<"\n";
//         i = i + 1;
//     }
//}


//  #include<iostream>
//  using namespace std;

//  int main(){
//     int n=4;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<=i;j++){
//             cout<<i+j+1;                      1st part of above question by another logic

//         }
//         cout<<endl;
//     }
//  }


// #include<iostream>
// using namespace std;

// int main(){
//    int n=4;
//    for(int i=1;i<n+1;i++){
//       int p=2*i;
//       for(int j=0;j<i;j++){
                                                    // 2nd part of above question by another logic

//          cout<<p;
//          p--;
//       }
//       cout<<endl;
//    }
// }

/*
Pattern
N = 5
  *
 ***
*****
 ***
  *
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
      for(int j=0;j<n-i-1;j++){
         cout<<" ";
      }

      for(int j=0;j<n+2*i-2;j++){
         cout<<"*";
      }
      cout<<endl;
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<=i;j++){
         cout<<" ";
      }

      for(int j=0;j<n-(2*i);j++){
         cout<<"*";
      }
      cout<<endl;
    }
    }
