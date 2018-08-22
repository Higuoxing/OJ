#include <iostream>
using namespace std;
long gcd(long m, long n) {
  if (n == 0)
    return m;
  return gcd(n, m % n);
}
string to_str(long m, long n) {
  string res = "";
  if (m == 0)
    return "0";
  long factor = 0;
  factor = gcd(m, n);
  long a = m,
      b = 0;
  if (factor != 0) {
    a = m / factor;
    b = n / factor;
  }
  if (b < 0) {
    b = -b;
    a = -a;
  }
  long x = 0, y = 0, z = 0;
  //     y
  //  x ---
  //     z
  x = a / b;
  y = a % b;
  z = b;
  if (a < 0)
    res += "(";
  if (x != 0)
    res = res + to_string(x);
  if (y != 0) {
    if (x != 0 && y < 0)
      y = -y;
    if (x != 0)
      res += " ";
    res = res + to_string(y) + "/" + to_string(b);
  }
  if (a < 0)
    res += ")";
  return res;
}

int main() {
  long a = 0, b = 0, c = 0, d = 0;
  //  a    c
  // ---  ---
  //  b    d
  scanf("%ld/%ld %ld/%ld", &a, &b, &c, &d);
  cout << to_str(a, b) << " + " << to_str(c, d) << " = " << to_str(a*d + b*c, b*d) << endl;
  cout << to_str(a, b) << " - " << to_str(c, d) << " = " << to_str(a*d - b*c, b*d) << endl;
  cout << to_str(a, b) << " * " << to_str(c, d) << " = " << to_str(a*c, b*d)       << endl;
  if (c == 0 && a > 0)
    cout << to_str(a, b) << " / " << to_str(c, d) << " = " << "Inf";
  else if (c == 0 && a < 0)
    cout << to_str(a, b) << " / " << to_str(c, d) << " = " << "-Inf";
  else
    cout << to_str(a, b) << " / " << to_str(c, d) << " = " << to_str(a*d, b*c);
  return 0;
}

