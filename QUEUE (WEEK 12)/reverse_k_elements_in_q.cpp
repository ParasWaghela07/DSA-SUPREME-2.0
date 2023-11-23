#include<bits/stdc++.h>
using namespace std;

//MY SOLUTION

void reverse(queue<int>&q){
    if(q.empty()){
        return;
    }
    int temp=q.front();
    q.pop();

    reverse(q);
    q.push(temp);
}

queue<int> reverseKelements(queue<int>&q,int k){
    queue<int>qn;

    while(k){
        int temp=q.front();
        q.pop();

        qn.push(temp);
        k--;
    }

    reverse(qn);

    while(!q.empty()){
        int temp=q.front();
        q.pop();

        qn.push(temp);
    }

    return qn;

}


//LOVE BABBAR'S SOLUTION
void reverseFirstKelements(queue<int>&q,int k){

    int n=q.size();
    if(k<n || k==0){
        return;
    }
    int count=n-k;
    stack<int>st;
    

    while(k){
        int temp=q.front();
        q.pop();
        st.push(temp);
        k--;
    }

    while(!st.empty()){
        int temp=st.top();
        st.pop();

        q.push(temp);
    }

    

    while(count){
        int temp=q.front();
        q.pop();

        q.push(temp);
        count--;
    }


}

int main(){
    queue<int>q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    // q.push(6);
    // q.push(7);

    // queue<int>ans=reverseKelements(q,2);

    reverseFirstKelements(q,3);



    // while(ans.empty()==0){
    //     cout<<ans.front()<<" ";
    //     ans.pop();
    // }

    while(q.empty()==0){
        cout<<q.front()<<" ";
        q.pop();
    }

    cout<<endl;
}