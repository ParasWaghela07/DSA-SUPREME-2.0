int byRecursion(int n){
    if(n==1) return 0;
    if(n==2) return 1;

    return (n-1)*(byRecursion(n-1)+byRecursion(n-2));
}