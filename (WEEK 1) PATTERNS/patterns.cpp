#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "ENTER NUMBER OF ROWS" << endl;
    cin >> n;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<"*";                                           //solid square
    //     }
    //     cout<<endl;
    // }




    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(i==0 || i==n-1 || j==0 || j==n-1){
    //             cout<<"*"<<" ";
    //         }
    //         else{                                                      hollow sqaure
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }



    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i;j++){
    //         if(i==0 || j==0 || i==n-1 || j==n-i-1)
    //         cout<<"*"<<" ";                                             //hollow pyramid
    //         else
    //         cout<<"  ";
    //     }
    //     cout<<endl;
    // }




    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i;j++){
    //         cout<<" ";
    //     }
    //     for(int k=0;k<=i;k++){
    //         cout<<"*";                                              // Full Pyramid
    //     }
    //     for(int p=0;p<i;p++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }




    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n - i; j++)
    //     {
    //         cout << " ";
    //     }
        
    //     for (int k = 0; k <= i; k++)
    //     {
    //         if(i==0 || i==n-1 ||k==0)
    //         cout << "*";
    //         else
    //         cout<<" ";
    //     }
    //                                                           //Hollow Full Pyramid
    //     for (int p = 0; p < i; p++)
    //     {
    //         if(i==0 || i==n-1 || p==i-1)
    //         cout << "*";
    //         else
    //         cout<<" ";
    //     }
    //     cout << endl;
    // }





    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<j+1;                           //numeric half pyramid
    //     }
    //     cout<<endl;
    // }




//  for(int i=0;i<n;i++){
//         for(int j=0;j<n-i;j++){
//             cout<<j+1;                           //numeric inverted half pyramid
//         }
//         cout<<endl;
//     }




// for(int i=0;i<n;i++){
//     for(int j=0;j<n-i;j++){
//         cout<<" ";
//     }
//     for(int j=0;j<i+1;j++){                        //full pyramid 2.0
//         cout<<"* ";
//     }
//     cout<<endl;
// }





// for(int i=0;i<n;i++){
//     for(int j=0;j<i;j++){
//         cout<<" ";
//     }
//     for(int j=0;j<n-i;j++){                      //inverted full pyramid
//         cout<<"* ";
//     }
//     cout<<endl;
// }





// for(int i=0;i<n;i++){
//     for(int j=0;j<n-i;j++){
//         cout<<" ";
//     }
//     for(int j=0;j<i+1;j++){                        
//         cout<<"* ";
//     }
//     cout<<endl;
// }                                          //diamond

// for(int i=0;i<n;i++){
//     for(int j=0;j<=i;j++){
//         cout<<" ";
//     }
//     for(int j=0;j<n-i;j++){                      
//         cout<<"* ";
//     }
//     cout<<endl;
// }






// for(int i=0;i<n;i++){
//     for(int j=0;j<n-i-1;j++){
//         cout<<" ";
//     }
//     for(int j=0;j<i+1;j++){
//         if(i==0 || i==n-1||j==0 || j==i)
//         cout<<"* ";                             //hollow full pyra 2.0
//         else
//         cout<<"  ";
//     }
//     cout<<endl;
// }






// for(int i=0;i<n;i++){
//     for(int j=0;j<i;j++){
//         cout<<" ";
//     }
//     for(int j=0;j<n-i;j++){                 inverted hollow full pyra 2.0
//         if(j==0 || j==n-i-1)
//         cout<<"* ";
//         else
//         cout<<"  ";
//     }
//     cout<<endl;
// }






// for(int i=0;i<n;i++){
//     for(int j=0;j<n-i-1;j++){
//         cout<<" ";
//     }
//     for(int j=0;j<i+1;j++){
//         if(j==0 || j==i)
//         cout<<"* ";                             
//         else
//         cout<<"  ";
//     }
//     cout<<endl;
// }
//                                                   //hollow diamond
// for(int i=0;i<n;i++){
//     for(int j=0;j<i;j++){
//         cout<<" ";
//     }                                        
//     for(int j=0;j<n-i;j++){                 
//         if(j==0 || j==n-i-1)
//         cout<<"* ";
//         else
//         cout<<"  ";
//     }
//     cout<<endl;
// }

                                


// for(int i=0;i<n;i++){
//     for(int j=0;j<i;j++){
//         cout<<" ";
//     }
//     for(int j=0;j<2*n-2*i-1;j++){
//         if(i==0 || i==n-1||j==0 || j==(2*n-2*i-2))
//         cout<<"*";
//         else
//         cout<<" ";                             //   hollow full pyramid 1.0 by 2n-2i-1
//     }
//     cout<<endl;
// }





// for(int i=0;i<n;i++){
//     for(int j=0;j<n-i;j++){
//         cout<<"*";
//     }
//     for(int j=0;j<2*i+1;j++){
//         cout<<" ";
//     }
//     for(int j=0;j<n-i;j++){
//         cout<<"*";
//     }
//     cout<<endl;
// }
//                                                              //flipped solid diamond
// for(int i=0;i<n;i++){
//     for(int j=0;j<=i;j++){
//         cout<<"*";
//     }
//     for(int j=0;j<2*n-2*i-1;j++){
//         cout<<" ";
//     }
//     for(int j=0;j<=i;j++){
//         cout<<"*";
//     }
//     cout<<endl;
// }





// for(int i=0;i<n;i++){
//     for(int j=0;j<2*i+1;j++){
//         if(j%2==1)
//         cout<<"*";
//         else                                // odd  places star and even places row number
//         cout<<i+1;
//     }
    
//     cout<<endl;
// }







// for(int i=0;i<n;i++){
//     for(int j=0;j<=i;j++){
//         cout<<i+1;
//         if(j!=i)                       same as previous but different logic
//         cout<<"*";
//     }
//     cout<<endl;
// }


// for(int i=0;i<n;i++){
//     for(int j=0;j<n-i;j++){
//         cout<<n-i;
//         if(j!=n-i-1)                 //inverted of previous
//         cout<<"*";
//     }
//     cout<<endl;
// }

// for(int i=0;i<n;i++){
//     for(int j=0;j<=i;j++){
//         cout<<i+1;
//         if(j!=i)                       
//         cout<<"*";
//     }
//     cout<<endl;
// }
//                                             //combination of previous two (half diamond)

// for(int i=0;i<n-1;i++){
//     for(int j=0;j<n-i-1;j++){
//         cout<<n-i-1;
//         if(j!=n-i-2)                 
//         cout<<"*";
//     }
//     cout<<endl;
// }








// for(int i=0;i<n;i++){
//     for(int j=0;j<n-i;j++){
//         if(i==0 || i==n-1 ||j==0||j==n-i-1)
//         cout<<"* ";
//     else{
//         cout<<"  ";                              //inverted hollow half
//     }
    
//     }
//     cout<<endl;
//  }






// for(int i=0;i<n;i++){
//     for(int j=0;j<i+1;j++){
//         if(i==0 || i==n-1 || j==0 || j==i)
//         cout<<j+1<<" ";
        
//         else
//         cout<<"  ";       //hollow py print cols 
        
//     }
//     cout<<endl;                                
// }




// for(int i=0;i<n;i++){
// char ch;
//     for(int j=0;j<2*i+1;j++){
//         if(j<=i){
//             ch='A'+j;
//             cout<<ch;
//         }
//         else{
//             ch=ch-1;
//             cout<<ch;
//         }
//     }                                       // ulta sidha combined character half pyra
//     // for(char alpha=ch;alpha>'A';){
//     //     alpha--;
//     //    cout<<alpha;
//     // }
//     cout<<endl;
// }




// for(int i=0;i<n;i++){
//     for(int j=0;j<n-i;j++){
//         if(i==0)
//         cout<<j+1<<" ";
//         else if(j==0)
//         cout<<i+1<<" ";                    //numeric hollow inverted half pyra
//         else if(j==n-i-1)
//         cout<<n<<" ";
//         else
//         cout<<"  ";
//     }
//     cout<<endl;
// }

// for(int i=0;i<n;i++){
//     for(int j=0;j<n-i;j++){
//         if(i==0 || i==n-1 || j==0 || j==n-i-1){ //optimized above
//             cout<<i+j+1;
//             cout<<" ";
//         }
//         else{
//             cout<<"  ";
//         }
//     }
//     cout<<endl;
// }






// for(int i=0;i<n;i++){
//     for(int j=0;j<=i;j++){
//         cout<<"* ";
//     }
//     cout<<endl;
// }
//                                                    // half diamond
// for(int i=0;i<n-1;i++){
//     for(int j=0;j<n-i-1;j++){
//         cout<<"* ";
//     }
//     cout<<endl;
// }







// int count=1;
// for(int i=0;i<n;i++){
//     for(int j=0;j<=i;j++){
//         cout<<count<<" ";                        //floy'd triangle
//         count++;
//     }
//     cout<<endl;
// }






// for(int i=0;i<n;i++){
//     for(int j=0;j<n-i;j++){
//         cout<<" ";
//     }
//     for(int j=0;j<=i;j++){
//         cout<<j+1;
//     }                                             //pascals triangle
//     for(int j=i;j>0;j--){
//         cout<<j;
//     }
//     cout<<endl;
// }

// for(int i=0;i<n;i++){
//     for(int j=0;j<n-i;j++){
//         cout<<" ";
//     }
//     for(int j=0;j<2*i+1;j++){
//         if(j<=i){
//             cout<<j+1;
//         }
//         else{
//             cout<<(i+1)-(j-i); //pivot k baad j and i ka diff minus krege
//         }
//     }
//     cout<<endl;
// }





// for(int i=0;i<n;i++){
//     for(int j=0;j<(2*n-i-2);j++){
//         cout<<"* ";
//     }
//     for(int j=0;j<2*i+1;j++){
//         cout<<i+1<<" ";
//         if(j!=i)                                         //around starts of even no. till 4 , at center full pyra of row no with stars
//         cout<<"* ";                                           
//     }
//     // for(int j=0;j<2*i+1;j++){   //straight  way
//     //     if(j%2==0){
//     //         cout<<i+1<<" ";
//     //     }
//     //     else{
//     //         cout<<"* ";
//     //     }                             
//     // }
//     for(int j=0;j<(2*n-i-2);j++){
//         cout<<"* ";
//     }
//     cout<<endl;
// }







// for(int i=0;i<n;i++){
//     for(int j=0;j<=i;j++){
//         cout<<"* ";
//     }
//     for(int j=0;j<2*n-2*i-2;j++){
//         cout<<"  ";
//     }
//     for(int j=0;j<=i;j++){
//         cout<<"* ";
//     }
//     cout<<endl;
// }
//                                                          //butterfly
// for(int i=0;i<n;i++){
//     for(int j=0;j<n-i;j++){
//         cout<<"* ";
//     }
//     for(int j=0;j<2*i;j++){
//         cout<<"  ";
//     }
//     for(int j=0;j<n-i;j++){
//         cout<<"* ";
//     }
//     cout<<endl;
// }


// int odd=1;
// for(int i=0;i<n;i++){
//         for(int j=0;j<n-i-1;j++){
//             cout<<" ";
//         }

//         for(int j=0;j<odd;j++){
//             cout<<"*";
//         }
//         odd=odd+2;
//         cout<<endl;
// }
// int odd2=odd-4;
// for(int i=0;i<n;i++){                           //perfect diamond
//         for(int j=0;j<=i;j++){
//             cout<<" ";
//         }

//         for(int j=0;j<odd2;j++){
//             cout<<"*";
//         }
//         odd2=odd2-2;
//         cout<<endl;
// }

// for(int i=0;i<n;i++){  //same as above
//     for(int j=0;j<n-i;j++){
//         cout<<" ";
//     }
//     for(int j=0;j<2*i+1;j++){
//         cout<<"*";
//     }
//     cout<<endl;
// }

// for(int i=0;i<n-1;i++){
//     for(int j=0;j<=i+1;j++){
//         cout<<" ";
//     }
//     for(int j=1;j<2*n-2*i-2;j++){
//         cout<<"*";
//     }
//     cout<<endl;
// }
int pivot=0;
int flag=0;
for(int i=0;i<n;i++){
    cout<<"|";
    for(int j=0;j<3;j++){
        if(j==pivot){
            cout<<"* ";
        }
        else{
            cout<<"  ";
        }
    }
    if(flag==0){
        if(pivot<2)
        pivot++;
        else
        flag=1;
    }
    if(flag==1){
        if(pivot>0)
        pivot--;
        else{
            flag=0;
            pivot++;
        }
    
    }
    cout<<endl;
}

}