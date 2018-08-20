#include <iostream>
using namespace std;
long long gcd(long long m, long long n) {
  if (n == 0)
    return m;
  else
    return gcd(n, m % n);
}

string simplify(long long a, long long b) {
  if (a == 0)
    return "0";
  char s[50];
  long long g = gcd(abs(a), abs(b));
  long long a_ = a / g,
       b_ = b / g;
  long long integer = a_ / b_,
       numerator = a_ % b_;
  if (a < 0)
    numerator = - numerator;
  if (integer == 0)
    sprintf(s, "%lld/%lld", numerator, b_);
  else if (numerator == 0)
    sprintf(s, "%lld", integer);
  else
    sprintf(s, "%lld %lld/%lld", integer, numerator, b_);
  string ss = string(s);
  if (integer < 0 || numerator < 0)
    ss = "(" + ss + ")";
  return ss;
}

int main() {
  string s0, s1;
  long long a, b, c, d;
  cin >> s0 >> s1;
  sscanf(s0.c_str(), "%lld/%lld", &a, &b);
  sscanf(s1.c_str(), "%lld/%lld", &c, &d);
  long long e, f;

plus:
  e = a * d + b * c;
  f = b * d;
  cout << simplify(a, b) << " + " << simplify(c, d)
    << " = " << simplify(e, f) << endl;
sub:
  e = a * d - b * c;
  f = b * d;
  cout << simplify(a, b) << " - " << simplify(c, d)
    << " = " << simplify(e, f) << endl;
mul:
  e = a * c;
  f = b * d;
  cout << simplify(a, b) << " * " << simplify(c, d)
    << " = " << simplify(e, f) << endl;
divide:
  if (c == 0) {
    if (a < 0) {
      cout << simplify(a, b) << " / " << simplify(c, d)
        << " = " << "-Inf" << endl;
    } else {
      cout << simplify(a, b) << " / " << simplify(c, d)
        << " = " << "Inf" << endl;
    }
  } else {
    e = a * d;
    f = b * c;
    if (f < 0) {
      e = - e;
      f = - f;
    }
    cout << simplify(a, b) << " * " << simplify(c, d)
      << " = " << simplify(e, f) << endl;
  }

  return 0;
}
