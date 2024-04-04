class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int mval=0;
        int pval=0;
        int gval=0;

        int lastm=0;
        int lastp=0;
        int lastg=0;
        for(int i=0;i<garbage.size();i++){
            string s=garbage[i];
            for(int j=0;j<s.size();j++){
                if(s[j]=='M'){
                    lastm=i;
                    mval++;
                }
                else if(s[j]=='P'){
                    lastp=i;
                    pval++;
                }
                else{
                    lastg=i;
                    gval++;
                }
            }
        }

        for(int i=0;i<lastm;i++){
            mval+=travel[i];
        }

        for(int i=0;i<lastp;i++){
            pval+=travel[i];
        }

        for(int i=0;i<lastg;i++){
            gval+=travel[i];
        }
        cout<<"M "<<mval<<endl<<"P "<<pval<<endl<<"G "<<gval<<endl;
        return mval+pval+gval;
    }
};