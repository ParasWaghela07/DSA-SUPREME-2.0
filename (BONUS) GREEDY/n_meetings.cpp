#include<bits/stdc++.h>
using namespace std;

int main(){
    int st[] = {10,12,20,19,28};
	int end[] = {20,25,30,36,40};
	int n = 5;

    //sort end array in ascending order , accordingly st array also

    int ans=1;
    int prevMeetEndTime=end[0];
    for(int i=1;i<n;i++){
        if(st[i]>prevMeetEndTime){
            ans++;
            prevMeetEndTime=end[i];
        }
    }

    cout<<"Meeting :- "<<ans<<endl;
}