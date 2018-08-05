/**
 * File              : Solution.cc
 * Author            : Xing GUO <higuoxing@seu.edu.cn>
 * Date              : 14.01.2018
 * Last Modified Date: 14.01.2018
 * Last Modified By  : Xing GUO <higuoxing@seu.edu.cn>
 */

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0;
        int current_points = 0;
        stack<int> round_points;
        for (auto ch : ops) {
            if (ch == "C") {
                res -= current_points;
                round_points.pop();
                if (!round_points.empty()) current_points = round_points.top();
                else current_points = 0;
            } else if (ch == "D") {
                current_points *= 2;
                round_points.push(current_points);
                res += current_points;
            } else if (ch == "+") {
                int tmp;
                tmp = round_points.top();
                round_points.pop();
                current_points += round_points.top();
                round_points.push(tmp);
                round_points.push(current_points);
                res += current_points;
            } else {
                current_points = std::stoi(ch);
                round_points.push(current_points);
                res += current_points;
            }
        }
        return res;
    }
};
