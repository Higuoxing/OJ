class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        for (char r : s) c ^= r;
        for (char r : t) c ^= r;
        return c;
    }
};
