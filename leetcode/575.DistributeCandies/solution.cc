/**
 * File              : solution.cc
 * Author            : Xing GUO <higuoxing@seu.edu.cn>
 * Date              : 14.01.2018
 * Last Modified Date: 14.01.2018
 * Last Modified By  : Xing GUO <higuoxing@seu.edu.cn>
 */
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        vector<int> candyCate;
        std::sort(candies.begin(), candies.end());
        int current = -100001;
        int last = -100001;
        for (auto i : candies) {
            current = i;
            if (current != last) {
                candyCate.push_back(i);
            }
            last = current;
        }
        return (candyCate.size() >= candies.size() / 2) ? \
            candies.size() / 2 : candyCate.size();
    }
};
