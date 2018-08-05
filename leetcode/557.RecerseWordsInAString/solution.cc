class Solution {
public:
    string reverseWords(string s) {
        s += " ";
        string tmp = "";
        string result = "";
        for (int i = 0; i < s.size(); i ++) {
            tmp += s[i];
            if (s[i] == ' ') {
                result += reverseString(tmp);
                tmp = "";
            }
        }
        return result.substr(1,result.size());
    }
    
    string reverseString(string s) {

        string *tmp;
        tmp = new string;
        for (int i = 0; i < s.size(); i ++) {
            tmp[0] += s[s.size() - i - 1];
        }
        return *tmp;
    }
};
