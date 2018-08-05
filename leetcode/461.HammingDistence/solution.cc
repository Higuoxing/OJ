#include <iostream>

class Solution {
	public:
		int hammingDistance(int x, int y) {
			return sum_of_bits(x ^ y);
		}

		int sum_of_bits(int num) {
			int ans = 0;
			while(num/2.0 != 0) {
				ans += num % 2;	
				num /= 2 ;
			}
			return ans;
		}
};

int main() {
	Solution sol;
	int ans = sol.hammingDistance(1, 4);
	std::cout << ans;
	return 0;
}
