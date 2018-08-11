#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
  string n, m = "";
  int digit[10];
  fill(digit, digit + 10, 0);
  cin >> n;
  // cal digits occurance
  for (int i = 0; i < n.length(); ++ i) {
    ++ digit[(int) (n[i] - '0')];
  }
  reverse(n.begin(), n.end());
  int carry = 0;
  for (int i = 0; i < n.length(); ++ i) {
    int this_digit = 2*(n[i] - '0') + carry;
    m += to_string(this_digit % 10);
    carry = this_digit / 10;
  }

  while (carry != 0) {
    m += to_string(carry % 10);
    carry /= 10;
  }

  reverse(m.begin(), m.end());

  for (int i = 0; i < m.length(); ++ i) {
    -- digit[(int) (m[i] - '0')];
  }

  int flag = 1;
  for (int i = 0; i < 10; ++ i) {
    if (digit[i] != 0) {
      flag = 0;
      break;
    }
  }

  if (flag == 1) {
    cout << "Yes\n" << m;
  } else
    cout << "No\n" << m;

  return 0;
}
