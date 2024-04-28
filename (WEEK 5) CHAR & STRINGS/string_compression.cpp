class Solution {
public:

    EXTRA SPACE

    int compress(vector<char>& chars) {
        int i = 0;
        int index = 0;

        while (i < chars.size()) {
            char c = chars[i];
            int count = 0;

            while (i < chars.size() && c == chars[i]) {
                count++;
                i++;
            }

            chars[index] = c;
            index++;

            if (count > 1) {
                string cnt = to_string(count);
                for (auto it : cnt) {
                    chars[index] = it;
                    index++;
                }
            }
        }

        return index;
    }
};

WITHOUT EXTRA SPACE 

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int index = 0;

        while (i < chars.size()) {
            char c = chars[i];
            int count = 0;

            while (i < chars.size() && c == chars[i]) {
                count++;
                i++;
            }

            chars[index] = c;
            index++;

            if (count > 1) {
                int start=index;
                while(count){
                    chars[index]=(count%10)+ '0';
                    index++;

                    count=count/10;
                }
                reverse(chars.begin()+start,chars.begin()+index);
            }
        }

        return index;
    }
};