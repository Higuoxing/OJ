#include<iostream>
#include<string>

using namespace std;

class Solution {
	public:
		string reverseString(string s) {

			string *tmp;
			tmp = new string;
			for (int i = 0; i < s.size(); i ++) {
				tmp[0] += s[s.size() - i - 1];
			}
			return *tmp;
		}
};

int main() {

	string s = "2333";
	Solution sol;
	cout << sol.reverseString(s);
	return 0;
}
