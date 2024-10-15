#include<iostream>
using namespace std;
int main(){
    int n,sec;
    cout<<endl<<"DO YOU WANNA KNOW A SECRET ?"<<endl;
    cout<<"Press 1 ==> YES \nPress 2 ==> NO"<<endl;
    cin>>sec;

    if(sec==1){
        cout<<"Select Any Number between 3 - 10 :-"<<endl;
    cin>>n;

cout<<endl<<endl;
for(int i=0;i<2*n;i++){

    for(int j=0;j<2*n-(n/4);j++){
        cout<<" ";
    }

    for(int j=0;j<(2*n)+1;j++){
   if(i==0 || i==2*n-1 || j==n)
        cout<<"* ";
    
    else
        cout<<"  ";
    }
    cout<<endl;
}
cout<<endl<<endl<<endl;










for(int i=0;i<n;i++){
    for(int j=0;j<n-i;j++){
        cout<<"  ";
    }
    for(int j=0;j<=i;j++){
        cout<<"* ";
    }
    for(int j=0;j<i;j++){
        cout<<"* ";
    }
    for(int j=0;j<2*n-2*i-2;j++){                 
             cout<<"  ";
        }
     for(int j=0;j<=i;j++){
        cout<<"* ";
    }
    for(int j=0;j<i;j++){
        cout<<"* ";
    }
    cout<<endl;
}
 for(int i=0;i<2*n;i++){
        for(int j=0;j<=i;j++){
            cout<<"  ";
        }
        for(int j=0;j<2*n-i-1;j++){
            cout<<"* ";
        }
        for(int j=0;j<2*n-i-1;j++){
            cout<<"* ";
        }
        cout<<endl;
  }
  cout<<endl;









  for(int i=0;i<2*n;i++){
    for(int j=0;j<(5*n)/2;j++){
        cout<<" ";
    }

    for(int j=0;j<2*n-(n/2);j++){
        if(j==0 || j==2*n-(n/2)-1||i==2*n-1)
        cout<<"* ";
        else
        cout<<"  ";
    }
    cout<<endl;
  }
}

else{
    cout<<endl<<"OKAY,IF YOU WANNA KNOW , THEN YOU CAN REACH ME ANYTIME !...\n";
}

}
















//     for(int i=0;i<n;i++){
//         for(int j=0;j<n-i-1;j++){
//             cout<<"0";
//         }                                       1st try
//         for(int j=0;j<=i;j++){
//             cout<<"* ";
//         }
//         for(int j=0;j<2*n-2*i-2;j++){
//             cout<<"0";
//         }
//         for(int j=0;j<=i;j++){
//             cout<<"* ";
//         }
        
//         cout<<endl;
//     }
//     for(int i=0;i<2*n;i++){
//         for(int j=0;j<i;j++){
//             cout<<"0";
//         }
//         for(int j=0;j<2*n-i;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }

// for(int i=0;i<n;i++){
//     for(int j=0;j<n-i;j++){
//         cout<<"  ";
//     }
//     for(int j=0;j<=i;j++){
//          cout<<" *  ";                                 
//     }
//     for(int j=0;j<2*n-2*i-2;j++){
//              cout<<"  ";
//         }                                         
//                                                         // 2nd try
//         for(int j=0;j<=i;j++){
//              cout<<"*   ";
//          }
//     cout<<endl;
// }

//  for(int i=0;i<2*n;i++){
//         for(int j=0;j<=i;j++){
//             cout<<"  ";
//         }
//         for(int j=0;j<2*n-i;j++){
//             cout<<"  * ";
//         }
//         cout<<endl;
//   }


// for(int i=0;i<n;i++){
//     for(int j=0;j<n-i;j++){
//         cout<<"  ";
//     }
//     for(int j=0;j<=i;j++){
//         cout<<"* ";
//     }
//     for(int j=0;j<i;j++){
//         cout<<"* ";
//     }
//     for(int j=0;j<2*n-2*i-2;j++){                 3rd try
//              cout<<"  ";
//         }
//         for(int j=0;j<=i;j++){
//         cout<<"* ";
//     }
//     for(int j=0;j<i;j++){
//         cout<<"* ";
//     }
//     cout<<endl;
// }
//  for(int i=0;i<2*n;i++){
//         for(int j=0;j<=i;j++){
//             cout<<"  ";
//         }
//         for(int j=0;j<2*n-i-1;j++){
//             cout<<"* ";
//         }
//         for(int j=0;j<2*n-i-1;j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//   }
