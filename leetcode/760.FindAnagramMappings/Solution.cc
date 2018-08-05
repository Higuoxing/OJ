/**
 * File              : Solution.cc
 * Author            : Xing GUO <higuoxing@seu.edu.cn>
 * Date              : 14.01.2018
 * Last Modified Date: 14.01.2018
 * Last Modified By  : Xing GUO <higuoxing@seu.edu.cn>
 */

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res;
        for (int i = 0; i < A.size(); i ++) {
            for (int j = 0; j < B.size(); j ++) {
                if (A[i] == B[j]) {
                    res.push_back(j);
                    B[j] = -1;
                    break;
                }
            }
        }
        return res;
    }
};
