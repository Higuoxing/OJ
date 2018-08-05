/**
 * File              : Solution.cc
 * Author            : Xing GUO <higuoxing@seu.edu.cn>
 * Date              : 14.01.2018
 * Last Modified Date: 14.01.2018
 * Last Modified By  : Xing GUO <higuoxing@seu.edu.cn>
 */

// quotient remainder

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i ++) {
            if (isSelfDivideNumber(i, i)) {
                res.push_back(i);
            }
        }
        return res;
    }

    bool isSelfDivideNumber(int origin, int dec) {
        int quotient = dec / 10;
        int remainder = dec % 10;
        if (remainder != 0 && origin % remainder == 0) {
            if (quotient == 0) return true;
            else return isSelfDivideNumber(origin, quotient);
        } else return false;
    }
};
