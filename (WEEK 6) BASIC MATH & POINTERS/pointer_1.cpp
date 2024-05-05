#include <iostream>
using namespace std;

    // int a=5;
    //int *ptr=&a;

    //printing
    // a --> 5
    // &a --> add of a
    // *a --> error
    // ptr--> add of a
    // &ptr --> add of ptr
    // *ptr --> 5
    // *ptr + 2 --> 7


    //copy pointer
    //int *q=ptr;
    // q will behave exactly same as ptr for a // points to add of a // q will have own diff add

    //ARRAY
    //int arr[5]={1,2,3,4,5};
    //int *p=arr|| &arr[0] --> all are same points to base address

    //int *p=&arr; --> not possible , coz pointer is to integer no array
    // correction --> int (*p)[5]=&arr;

    //printing
    //arr || &arr ||&arr[0] --> base address
    // arr[0] --> 1st value
    // arr + 1 --> address of 2nd element

    //*p --> 1
    // *p + 1 --> (1) + 1 
    // *(p+3) --> goes to address 116 if base address is 104 // then prints value at 116 --> 4
    // *(p+i) == arr[i] == i[arr] --> value at ith index
    //(*ptr)[0] --> 1
    //(*ptr)[3] --> 4

    //ARRAY OF POINTERS 
    //int *arr[5];
    //int nums[5]={1,2,3,4,5};
    //*arr[0]=&nums[0];
    //*arr[4]=&nums[4];



    //CHAR ARRAY
    //char ch[10]="love";
    //char *cptr=ch || &ch[0];

    //printing
    // ch --> love
    // ch[0] --> l
    // cptr --> love
    // *cptr --> l
    // *cptr + 2 == ch[2] --> v
    // &ch --> base address
    // &cptr --> address
     // * (cptr + 1) == cptr + 1 --> from ch[1] till end 

int main() {

//   char ch[10] = "babbar";
//   cout << &ch[0];
//   char* cptr = &ch;

//   char ch[10] = "a";
//   char *cptr = ch;
//   cout << cptr;


//   int arr[5] = {1,2,3,4,5};
//   arr = arr + 1;




//   int a = 5;
//   int* p = &a;

//   p = p + 1;
//   cout << *p;
//   int* ptr = 0;
//   cout << *ptr << endl;


//   int a = 5;
//   cout << a << endl;
//   cout << "address of a : "<< &a << endl;
  

//   //pointer creation
//   int* ptr = &a;
//   //acessing value stored at address stored in ptr
//   cout << ptr << endl;
//   cout << "Accessing: " << *ptr << endl;
//   cout << &ptr << endl;


  return 0;
}