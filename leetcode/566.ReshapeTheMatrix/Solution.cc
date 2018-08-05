/**
 * File              : Solution.cc
 * Author            : Xing GUO <higuoxing@seu.edu.cn>
 * Date              : 14.01.2018
 * Last Modified Date: 14.01.2018
 * Last Modified By  : Xing GUO <higuoxing@seu.edu.cn>
 */

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.size() * nums[0].size() != r * c)
            return nums;
        else {
            vector<vector<int>> res;
            vector<int> row;
            for (auto i : nums) {
                for (auto j : i) {
                    if (row.size() < c)
                        row.push_back(j);
                    else {
                        res.push_back(row);
                        row.clear();
                        row.push_back(j);
                    }
                }
            }
            res.push_back(row);
            return res;
        }
    }
};
