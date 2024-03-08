int setKthBit(int N, int K)
    {
        // int M=pow(2,K);
        int M=1<<K;//bit masking
        return N|M;
        
    }