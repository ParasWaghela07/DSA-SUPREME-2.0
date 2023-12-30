class Solution ////////////// DYNAMIC PROGRAMMING QST , NOT SUBMITTED IN GFG
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        if(n==0){
            return 0;
        }
        if(n<0){
            return INT_MIN;
        }
        
        int op1=1+maximizeTheCuts(n-x,x,y,z);
        int op2=1+maximizeTheCuts(n-y,x,y,z);
        int op3=1+maximizeTheCuts(n-z,x,y,z);
        
        return max(max(op1,op2),op3);
    }
};
