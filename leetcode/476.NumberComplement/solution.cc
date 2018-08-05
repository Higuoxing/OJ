#include<iostream>

class Solution {
public:
    int findComplement(int num) {
		unsigned mask = ~ 0;
		while (num & mask) mask <<= 1;
		return ~ num & ~ mask;
    }
};

int main() {
	
	Solution sol;
	std::cout << sol.findComplement(4);
	return 0;
}
