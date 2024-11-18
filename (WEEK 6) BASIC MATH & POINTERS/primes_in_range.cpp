class Solution {
  public:
    vector<bool> Sieve(int n)
{
    // create a sieve array telling isPrime till 'n'
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

    /*for (int i = 2; i <= n; i++)*/
    for (int i = 2; i * i <= n; i++) // Optimisation 2: (Outer loop):
                                     // if i becomes > sqrt(N), then the
                                     // inner loop does not work.
    {
        if (sieve[i] == true)
        {
            // means, sieve[i] is Prime and mark its multiples
            //  as non-prime.
            /*int j = i * 2;*/
            int j = i * i; // Optimisation 1 (inner loop):
                           // first unmarked number would be i*i
                           // as, other have been marked by 2 to (i - 1).
            while (j <= n)
            {
                sieve[j] = false;
                j += i;
            }
        }
    }
    return sieve;
}

vector<bool> segmentedSeive(int L, int R)
{

    vector<bool> sieve = Sieve(sqrt(R));
    vector<int> basePrimes;
    for (int i = 0; i < sieve.size(); i++)
    {
        if (sieve[i])
            basePrimes.push_back(i);
    }

    vector<bool> segSieve(R - L + 1, true);
    if (L == 1)
    {
        segSieve[0] = false;
    }

    for (auto prime : basePrimes)
    {
        int first_mul = (L / prime) * prime;
        first_mul = first_mul < L ? first_mul + prime : first_mul;
        int j = max(first_mul, prime * prime);
        while (j <= R)
        {
            segSieve[j - L] = false;
            j += prime;
        }
    }
    return segSieve;
}
    
    vector<int> primeRange(int M, int N) {
        vector<bool> segsieve = segmentedSeive(M, N);
        vector<int>ans;
        for(int i=0;i<segsieve.size();i++){
            if(segsieve[i]) ans.push_back(M+i);
        }
        
        return ans;
    }
};