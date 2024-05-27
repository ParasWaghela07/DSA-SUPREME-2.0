    //heap memory is used to allocate memory during runtime only
    // we can only access heap using pointers
    //data needs to be manually deleted after using it or it causes memory leakage
#include<iostream>
using namespace std;

int main(){
    int a=5; // allocation of an integer on STACK MEMORY

    int *ptr= new int(5); // allocation of an ineteger on HEAP MEMORY
     // new keyword creates integer of 4 byte in heap and set value as 5 and return ADDRESS of that block 
     // TO STORE ADDRESS WE NEED POINTER

     // NOW USING POINTER WE CAN ACCESS INT allocated on heap

     //MALLOC
     void *iptr=malloc(4); // allocation on heap
     //malloc keyword does not know about datatype it only initilize number of bytes on heap and return address of that block
     //to store address we need pointer but we dont know the data type //malloc return void pointer storable type of address
     //so void pointer is used

     //to convert in into datatype
     int *cptr=(int*)iptr; // void pointer to integer pointer // implicit type casting 


     //shortcut
     int *sptr=(int*)malloc(4); // 
     *sptr=5;

     //to store value for that int
     *cptr=5;

     //now our int pointer is ready which is pointing at block having value 5 on heap memory
     //access
     cout<<"ptr :- "<<*ptr<<endl;
     cout<<"sptr :- "<<*sptr<<endl;
     cout<<"cptr :- "<<*cptr<<endl;

     delete ptr; //for new
     free(cptr); // for malloc
     free(sptr);


     //1-D ALLOCATION
     int *arr=new int[5]; //pointer to base address of array // array is allocated on heap of size 5

     //MALLOC
     int *arr1=(int*)malloc(20); // alloacted 20 bytes for 5 integers // 4 byte each and returning base address
     int *arr2=(int*)malloc(5*sizeof(int));//another way

     //access 
     for(int i=0;i<5;i++){
        int d;
        cin>>d;
        arr[i]=d;
        arr1[i]=d;
        arr2[i]=d;
     }

     for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
     }
     cout<<endl;
     for(int i=0;i<5;i++){
        cout<<arr1[i]<<" ";
     }
     cout<<endl;
     for(int i=0;i<5;i++){
        cout<<arr2[i]<<" ";
     }

     delete[] arr;
     free(arr1);
     free(arr2);


     //2D ALLOCATION
     //NEW
     // STEP 1:- make rows , outer container
      // for such allocation  we need to create a array of 1d arrays ... for each 1d array we req pointer so for many 1d arrays we required an array of pointers where each pointer is pointing to 1d array

      // for pointer to pointer
      int **pt1=new int*[5]; //here 5 is number of rows of 2d array // array of int*(pointers)

      //STEP 2:- make cols , inner 1d array values

      for(int i=0;i<5;i++){
        pt1[i]=new int[5]; // allocating each pointer to point to an array on heap // 5 is number of cols
      }

      //MALLOC

      // we have to allocate bytes so , for outer container , rows
      // each row elements contains pointer to an 1d array , size of pointer is 8

      int **pt2=(int**)malloc(sizeof(int*)*5); // 5 is number of rows

      for(int i=0;i<5;i++){
        pt2[i]=(int*)malloc(sizeof(int)*5); // here 5 is number of cols
      }

      //acessing

      for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            pt1[i][j]=7;
            pt2[i][j]=8;
        }
      }

      cout<<"2d array by new " << endl;

      for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<pt1[i][j]<<" ";
        }
        cout<<endl;
      }

      cout<<"2d array by malloc " << endl;

      for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<pt2[i][j]<<" ";
        }
        cout<<endl;
      }

      // deleting all 1d arrays
      for(int i=0;i<5;i++){
        delete[] pt1[i]; //new
        free(pt2[i]); //malloc
      }

      

      //deleting outer container // array of pointer to pointer
      delete[] pt1;
      free(pt2);


}