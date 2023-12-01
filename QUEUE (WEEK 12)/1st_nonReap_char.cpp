class Solution {
public:

//WITHOUT QUEUE 
    int firstUniqChar(string s) {
        
        int map[26]={0};

        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(map[ch-'a']==0)
            map[ch-'a']++;
        }

        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(map[ch-'a']==1){
                return i;
            }
        }

        return -1;






//WITH QUEUE
        queue<int>q;
        int map[26]={0};

        for(int i=0;i<s.size();i++){

            char ch=s[i];
            map[ch-'a']++;
            q.push(i);

            while(!q.empty() && map[s[q.front()]-'a']>1){
                q.pop();
            }
        }
        if(!q.empty()){
            return q.front();
        }
        else{
            return -1;
        }
        
    }
};