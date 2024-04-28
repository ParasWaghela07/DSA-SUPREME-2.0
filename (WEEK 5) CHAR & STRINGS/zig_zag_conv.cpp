class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<vector<char>> v(numRows, vector<char>(s.size(), '-'));

        int index = 0;
        int i = -1;
        int j = 0;

        while (index < s.size()) {

            while (index < s.size() && i+1 < numRows) {
                    i++;
                    v[i][j] = s[index];
                    index++;
            }

            while (index < s.size() && i-1 >= 0) {
                    i--;
                    j++;
                    v[i][j] = s[index];
                    index++;
            }
        }

        string ans;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[0].size(); j++) {
                if(v[i][j]!='-') ans.push_back(v[i][j]);
            }
        }

        return ans;
    }
};