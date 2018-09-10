#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string add(string s0, string s1) {
  size_t t = max(s0.length(), s1.length()) + 1;
  string c(t, '0');
  reverse(s0.begin(), s0.end());
  reverse(s1.begin(), s1.end());
  int carry = 0;
  for (int i = 0; i < s0.length(); ++ i) {
    c[i] = s1[i] - '0' + s0[i] - '0' + carry;
    if (c[i] > 9) {
      carry = 1;
      c[i] -= 10;
    } else
      carry = 0;
    c[i] += '0';
  }
  if (carry != 0)
    c[c.size()-1] = '1';
  reverse(c.begin(), c.end());
  if (c[0] != '0')
    return c;
  else return c.substr(1);
}

bool is_palindromic(string c) {
  string tmp = c;
  reverse(c.begin(), c.end());
  if (tmp == c) return true;
  return false;
}

int main() {
  string n;
  int k, i = 0;
  cin >> n >> k;
  while (i != k && !is_palindromic(n)) {
    string tmp = n;
    reverse(tmp.begin(), tmp.end());
    n = add(tmp, n);
    ++ i;
  }
  cout << n << '\n' << i;
  return 0;
}
