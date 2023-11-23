#include<iostream>
#include<stack>
using namespace std;

//GET MID ELEMENT

void solve(stack<int> &st,int posi,int &ans){

    if(posi==1){
        ans=st.top();
        return;
    }

    int temp=st.top();
    st.pop();
    posi--;

    solve(st,posi,ans);

    st.push(temp);
}

//GET MID POSI



int getmid(stack<int> &st){
    int posi=-1;
    if(st.empty())
{
    return -1;
}    

    if(st.size()%2==0){
        posi=st.size()/2;
    }
    else if(st.size()%2!=0){
        posi=(st.size()/2)+1;
    }

    int ans=-1;
    solve(st,posi,ans);

    return ans;
    
}

void middel(stack<int> &st,int posi){

    if(posi==1){
        st.pop();
        return;
    }

    int temp=st.top();
    st.pop();
    posi--;

    middel(st,posi);

    st.push(temp);
}


void delmid(stack<int> &st){

    int posi=-1;

    if(st.size()%2==0){
        posi=st.size()/2;
    }
    else if(st.size()%2!=0){
        posi=(st.size()/2)+1;
    }

    middel(st,posi);

}

void print(stack<int> st){
    while(st.empty()!=1){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}




int main(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    // st.push(4);
    st.push(5);
    st.push(6);

    print(st);

    // cout<<getmid(st)<<endl;
    delmid(st);
    print(st);
    // cout<<getmid(st)<<endl;
}