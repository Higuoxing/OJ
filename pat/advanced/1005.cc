#include <iostream>
#include <string>
using namespace std;

int main() {
  string num;
  int sum = 0;
  cin >> num;
  string spelling[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
  // here must use big int or string to calculate;
  for (auto &i : num)
    sum += (int)(i - '0');
  string res = to_string(sum);
  for (int i = 0; i < res.length(); ++ i) {
    cout << spelling[(int)(res[i] - '0')];
    if (i != res.length()-1)
      cout << ' ';
  }
  return 0;
}
