#include<iostream>
using namespace std;

class Stack{
    public:
    int* arr;
    int size;
    int top;

    Stack(int size){
        arr=new int[size];
        this->size=size;
        this->top=-1;
    }

    void push(int data){
        if(top==size-1){
            cout<<"OVERFLOW\n";
        }
        else{
            top++;
            arr[top]=data;
        }
    }

    void pop(){
        if(top==-1){
            cout<<"UNDERFLOW\n";

        }
        else{
            cout<<arr[top]<<" IS POPPED\n";
            top--;
        }
    }

    void gettop(){
        if(top==-1){
            cout<<"stack is empty\n";
        }
        else
        cout<<arr[top]<<endl;
    }

    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

    int getsize(){
        return top+1;
    }

    void toprint(){
        if(top==-1){
            cout<<"stack is empty\n";
        }
        else{
        int temp=top;
        while(temp>=0){
            cout<<arr[temp]<<endl;
            temp--;
        }
        }
    }

};


int main(){

    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(3);
    st.push(69);
    st.gettop();
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    // st.toprint();

}