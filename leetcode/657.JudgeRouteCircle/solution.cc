#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
		
		int U = 0;
		int D = 0;
		int L = 0;
		int R = 0;

		if (moves.size() % 2 == 1) return false;
		else {
			
			for (int i = 0; i < moves.size(); i ++) {
				if (moves[i] == 'U') U++;
				else if (moves[i] == 'D') D++;
				else if (moves[i] == 'L') L++;
				else if (moves[i] == 'R') R++;
			}
			if ((D == U) && L == R) return true;
			else return false;
		}
    }
};

int main() {
	

	Solution sol;
	bool ans = sol.judgeCircle("UUUDLR");
	cout << ans;
	return 0;
}
