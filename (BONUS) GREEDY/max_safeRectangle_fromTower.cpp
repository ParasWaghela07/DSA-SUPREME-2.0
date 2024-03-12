#include<bits/stdc++.h>
using namespace std;

int main(){
     int row = 8;
     int col = 15;
     int tower = 3;

     vector<pair<int,int>>loc;
      loc.push_back({3, 8});
      loc.push_back({11, 2});
      loc.push_back({8, 6});

      vector<int>Xdist;
      Xdist.push_back(0);
      Xdist.push_back(col+1);
      for(auto it:loc){
        Xdist.push_back(it.first);
      }

      vector<int>Ydist;
      Xdist.push_back(0);
      Xdist.push_back(row+1);
      for(auto it:loc){
        Ydist.push_back(it.second);
      }

      sort(Xdist.begin(),Xdist.end());
      sort(Ydist.begin(),Ydist.end());

      vector<int>Xdiff;
      for(int i=1;i<Xdist.size();i++){
        Xdiff.push_back(Xdist[i]-Xdist[i-1]-1);
      }

      vector<int>Ydiff;
      for(int i=1;i<Ydist.size();i++){
        Ydiff.push_back(Ydist[i]-Ydist[i-1]-1);
      }

      int ans=INT_MIN;
      for(int i=0;i<Xdiff.size();i++){
        for(int j=0;j<Ydiff.size();j++){
            ans=max(ans,Xdiff[i]*Ydiff[j]);
        }
      }

      cout<<"Ans :- "<<ans<<endl;

}