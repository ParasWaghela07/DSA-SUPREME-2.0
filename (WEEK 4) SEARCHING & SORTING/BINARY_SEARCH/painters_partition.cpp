bool isSafe(vector<int> &boards, int k,int mid){
    int painters=1;
    int currVal=0;
    int i=0;

    while(i<boards.size()){
        if(painters > k ) return false;
        if(currVal+boards[i] > mid ){
            currVal=0;
            painters++;
        }
        else{
            currVal+=boards[i];
            i++;
        }
    }

    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
   int sum=0;
   for(int i=0;i<boards.size();i++){
       sum+=boards[i];
   }

   int s=1;
   int e=sum;
   int ans=-1;

   while(s<=e){
       int mid=s+(e-s)/2;

       if(isSafe(boards,k,mid)){
           ans=mid;
           e=mid-1;
       }
       else{
           s=mid+1;
       }
   }

   return ans;
}