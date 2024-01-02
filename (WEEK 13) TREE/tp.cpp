#include<iostream>
using namespace std;

int main(){
    cout<<"ENTER RS. : ";

    int n;
    cin>>n;

    int candy=n;
    int wrapper=n;

    while(wrapper>=3){
        int extra=wrapper/3;
        candy+=extra;
        wrapper=wrapper%3+extra;
    }

    cout<<"TOTAL CANDIES : "<<candy<<endl;
}