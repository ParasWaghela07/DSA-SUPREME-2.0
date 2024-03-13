       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i=0;
            int j=0;
            int k=0;
            
            vector<int>ans;
            
            while(i<n1 && j<n2 && k<n3){
                int maxi=max(A[i],max(B[j],C[k]));
                
                if(ans.size()>0 && maxi==ans[ans.size()-1]){
                    if(maxi==A[i]) i++;
                    if(maxi==B[j]) j++;
                    if(maxi==C[k]) k++;
                    
                    continue;
                }
                
                while(i<n1 && A[i]<maxi){
                    i++;
                }
                
                while(j<n2 && B[j]<maxi){
                    j++;
                }
                
                while(k<n3 && C[k]<maxi){
                    k++;
                }
                
                if(i<n1 && j<n2 && k<n3 && A[i]==B[j] && B[j]==C[k]){
                    ans.push_back(A[i]);
                    i++;
                    j++;
                    k++;
                }
            }
            
            return ans;
        }
