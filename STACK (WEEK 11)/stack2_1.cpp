//TWO STACKS IN ONE ARRAY

#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size){
        this->size=size;
        this->top1=-1;
        this->top2=size;
        arr=new int[size];
    }

void push1(int data){
if(top2-top1==1){
    cout<<"OVERFLOW"<<endl;
}
else{
    top1++;
    arr[top1]=data;
}
}

void pop1(){
    if(top1==-1){
        cout<<"UNDERFLOW"<<endl;
    }
    else{
        arr[top1]=0;
        top1--;
    }

}

void push2(int data){
if(top2-top1==1){
    cout<<"OVERFLOW"<<endl;
}
else{
    top2--;
    arr[top2]=data;
}
}

void pop2(){
if(top2==size){
        cout<<"UNDERFLOW"<<endl;
    }
    else{
        arr[top2]=0;
        top2++;
    }
}

void print(){
    cout<<"Top 1 = "<<top1<<endl<<"Top 2 = "<<top2<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}
};

int main(){
    Stack st(5);

    st.push1(1);
    st.push1(2);
    st.push1(3);
    
    st.push2(7);
    st.push2(8);

    st.pop1();
    st.push2(9);

    st.pop1();
    
    st.pop1();
    st.print();

}

