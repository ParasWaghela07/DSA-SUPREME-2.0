int byRecursion(int n){
    if(n==1) return 0;
    if(n==2) return 1;

    return (n-1)*(byRecursion(n-1)+byRecursion(n-2)); 

    //swap an element with other element , so 1 element is de-arranged (n-1) but other element will come at swapped element so remaining elements are n-2 ---> (n-1)*f(n-2)

    //swapped element do not require to placed at prev element position : (n-1)*f(n-1)

    //:--> final :--> (n-1)*f(n-1) + (n-1)*f(n-2)
}