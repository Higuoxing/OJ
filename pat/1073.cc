#include <iostream>
#include <cmath>
using namespace std;
int main() {
  string scinum, integer, decimal;
  cin >> scinum;
  int int_flag = 1,
      dec_flag = 0,
      exp_idx  = -1,
      expnum   = -1;
  for (int i = 1; i < scinum.length(); ++ i) {
    if (scinum[i] == '.') {
      int_flag = 0;
      dec_flag = 1;
    }
    if (scinum[i+1] == 'E') {
      dec_flag = 0;
      exp_idx = i + 2;
    }
    if (int_flag)
      integer.push_back(scinum[i]);
    if (dec_flag)
      decimal.push_back(scinum[i+1]);
  }
  expnum = stoi(scinum.substr(exp_idx, scinum.length()));
  if (expnum > 0) {
    if (expnum > decimal.length()) {
      decimal.insert(decimal.length(), expnum - decimal.length(), '0');
    } else if (expnum < decimal.length()) {
      decimal.insert(expnum, 1, '.');
    } else {

    }
  } else if (expnum < 0) {
    if (- expnum > integer.length()) {
      integer.insert(0, -expnum - integer.length() + 1, '0');
      integer.insert(1, 1, '.');
    } else if (- expnum < integer.length()) {
      integer.insert(integer.length() + expnum, 1, '.');
    } else {
      integer.insert(integer.length() + expnum, 1, '.');
      integer = "0" + integer;
    }
  } else {
    integer += ".";
  }
  if (scinum[0] == '-')
    integer = "-" + integer;
  cout << integer + decimal;
  return 0;
}
