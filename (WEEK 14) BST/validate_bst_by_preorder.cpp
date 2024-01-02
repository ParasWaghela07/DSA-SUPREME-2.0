void build(int &i,int min,int max,vector<int>a){
    if(i>=a.size()){
        return;
    }

    if(a[i]>min && a[i]<max){
        int rootVal=a[i++];
    build(i,min,rootVal,a);
    build(i,rootVal,max,a);
    }
    
}

bool solution(vector<int>&a){
    int min=INT_MIN;
    int max=INT_MAX;

    int i=0;
    build(i,min,max,a);

    return ( i==a.size());
}