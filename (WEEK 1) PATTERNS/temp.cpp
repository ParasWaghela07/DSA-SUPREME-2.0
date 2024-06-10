#include <iostream> 
using namespace std; 
 
int main() 
{ 
 
    int n, row, col; 
    cout << "Enter the no of rows and cols( square pyramid ) :"; 
    cin >> n; 
 
    for (row = 0; row < n; row++) 
    { 
        for (col = 0; col < n - row; col++) 
        { 
 
            if (row == 0 && row + col != n - 1) 
            { 
                cout << col + 1<< " "; 
            } 
            if (col + row == n - 1) 
            { 
                cout << n <<" "; 
            } 
 
            if (col == 0 && row != 0 && row != n - 1) 
            { 
                cout <<1 + row<<" "; 
            } 
            else 
            { 
                cout << " "; 
            } 

        }

        //     if(row==0){
        //         cout<<col+1<<" ";
        //     }
        //     else if(row==n-1){
        //         cout<<n<<" ";
        //     }
        //     else{
        //         if(col==0){
        //             cout<<row+1<<" ";
        //         }
        //         else if(col==n-row-1){
        //             cout<<n<<" ";
        //         }
        //         else{
        //             cout<<"  ";
        //         }
        //     }
        // } 
        cout << endl; 
    } 
 
    return 0; 
}