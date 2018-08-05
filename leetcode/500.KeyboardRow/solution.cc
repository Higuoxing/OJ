#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // -- Keymap Set
        string keyStr[] = {
            "QqWwEeRrTtYyUuIiOoPp",
            "AaSsDdFfGgHhJjKkLl",
            "ZzXxCcVvBbNnMm"
        };
        // -- initialize keymap set
        vector<string> keyString(keyStr, keyStr + 3);
        vector<string> result;
        for (int i = 0; i < words.size(); i ++) {
            if (isSameLine(keyString, words[i])) result.push_back(words[i]);
        }
        return result;
    }

    bool isSameLine(vector<string> keySet, string testString) {
        int firstChar = locateChar(keySet, testString[0]);
        for (int i = 1; i < testString.size(); i ++) {
            if (firstChar == locateChar(keySet, testString[i])) continue;
            else return false;
        }
        return true;

    }

    int locateChar(vector<string> keySet, char character) {
        for (int i = 0; i < keySet.size(); i ++) {
            for (int j = 0; j < keySet[i].size(); j ++) {
                if (keySet[i][j] == character) return i;
            }
        
        }
        return 3;
    }

};

int main(void) {

    Solution sol;
    string testStr[] = {
        "ASDGLHS",
        "sdfgh",
        "qwerty",
        "zxcvbn",
        "dehub"
    };
    vector<string> testString(testStr, testStr + 3);
    for (int i = 0; i < sol.findWords(testString).size(); i ++) {
        cout << sol.findWords(testString)[i] << endl;
    }

    return 0;
}
