int getWays(int n,int k){
    if(n==1) return k;
    if(n==2) return k+k*(k-1);

    return (k-1)*f(n-1) + (k-1)*f(n-2); // we can use 1 color to color 2 fench or 1 fench // we try both ways and add them
}