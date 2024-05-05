#include<bits/stdc++.h>
using namespace std;

//int a=5;
//int *p1=&a;

//int **p2=&a ---> not possible

//int **p2=&p1;
// int ***p3=&p2;

//printing
//a --> 5
// p1 --> add of p1
// *p1 --> 5
// p2 --> add of p2
// *p2 --> add of p1;
// **p2--> 5
// p3 --> add of p3
// *p3 --> add of p2
// **p3 --> add of p1
// ***p3 --> 5

void temp(int arr[]){
    cout<<sizeof(arr)<<endl;
    cout<<"arr :-"<<arr<<endl;
    cout<<"&arr :-"<<&arr<<endl;
}

int main(){
    int arr[]={1,2,3,4,5};
    cout<<sizeof(arr)<<endl;
    cout<<"MAIN arr :-"<<arr<<endl;
    cout<<"MAIN &arr :-"<<&arr<<endl;
    temp(arr);
}


#include <iostream>
using namespace std;

// void solve(int *arr, int size) {
// 	// cout << "Size of array inside solve func: " << sizeof(arr) << endl;
// 	// cout << "Inside solve -> arr: " << arr << endl;
// 	// cout << "Inside solve -> &arr: " << &arr << endl;
// 	*arr = *arr + 1;
// }
void solve(int* &p) {
	p = p + 1;
}
int main() {

	int a = 5;
	int* p = &a;

	cout << "p: " << p << endl;
	cout << "&p : " << &p << endl;
	cout << "*p: " << *p << endl;
	solve(p);
	cout << "p: " << p << endl;
	cout << "&p : " << &p << endl;
	cout << "*p: " << *p << endl;
	
	

	// int arr[] = {10,20,30};
	// ///cout << "Size of array: " << sizeof(arr) << endl;
	// solve(arr,3);

	// for(int i=0; i<3; i++) {
	// 	cout << arr[i] << " ";
	// }
	
	// // cout << "Inside main -> arr: " << arr << endl;
	// cout << "Inside main -> &arr: " << &arr << endl;

	// int arr[5] = {1,2,3,4,5};

	// //pointer to an array
	// int* ptr1 = arr;
	// //pointer to an array
	// int (*ptr)[5] = &arr;
	// cout << (*ptr)[0];
	

	// // char ch[10] = "Babbar";
	// // char* cptr = &ch;
	// here cptr[2] is also possible


	return 0;
}