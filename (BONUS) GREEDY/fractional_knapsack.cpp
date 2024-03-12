#include<bits/stdc++.h>
using namespace std;
int fractionalKnapsack(vector<int> val, vector<int> wt, int n, int capacity) {
	vector<float> valWtRatio;
	for(int i=0; i<n; i++) {
		float ratio  = (val[i] * 1.0) / wt[i];
		valWtRatio.push_back(ratio);
	}

	priority_queue<pair<float,pair<int,int> > > maxi;
	for(int i=0; i<n; i++) {
		maxi.push({valWtRatio[i], {val[i], wt[i] } } ); 
	}
	//max heap is ready 
	int totalVal = 0;
	while(capacity != 0 && !maxi.empty() ) {
		auto front = maxi.top();
		float ratio = front.first;
		int value = front.second.first;
		int weight = front.second.second;
		maxi.pop();
		//fulll insert hoga
		if(capacity >= weight) {
			totalVal += value;
			capacity = capacity - weight;
		}
		else {
			//fractional insert hoga
			int valueToInclude = ratio * capacity;
			totalVal += valueToInclude;
			capacity = 0;
			break;
		}
	}
	return totalVal;
}


int main(){
    vector<int>val={60,100};
    vector<int>wt={10,20};
    int m=20;

    int n=val.size();
    vector<float>ratio(n);
    for(int i=0;i<n;i++){
        float temp=(val[i]*1.0)/wt[i];
        ratio[i]=temp;

    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(ratio[j]<ratio[j+1]){
                swap(ratio[j],ratio[j+1]);
                swap(wt[j],wt[j+1]);
                swap(val[j],val[j+1]);
            }
        }
    }

    int i=0;
    float profit=0;
    while(i<n && m>0){
        if(wt[i]<=m){
            profit+=val[i];
            m=m-wt[i];
            i++;
        }
        else{
            float toAdd=ratio[i]*m;
            profit+=toAdd;
            break;
        }
    }

    cout<<"Profit:- "<<profit<<endl;
}