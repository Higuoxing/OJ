#include <iostream>
using namespace std;

long gcd(long m, long n) {
  if (n == 0)
    return m;
  return gcd(n, m % n);
}

void rational_sum(long a, long b, long c, long d, long *e, long *f) {
  // a/b + c/d = e/f
  *e = a * d + b * c;
  *f = b * d;
  long gcd_ef = gcd(*e, *f);
  *e = *e / gcd_ef;
  *f = *f / gcd_ef;
}

void to_ind(long a, long b, long *i, long *n, long *d) {
  *i = a / b;
  *n = a % b;
  *d = b;
}

int main() {
  long n, sum_n = 0, sum_d = 1;
  scanf("%ld", &n);
  for (int i = 0; i < n; ++ i) {
    long numer, deno;
    scanf("%ld/%ld", &numer, &deno);
    rational_sum(sum_n, sum_d, numer, deno, &sum_n, &sum_d);
  }
  long integer = 0, numerator = 0, denominator;
  to_ind(sum_n, sum_d, &integer, &numerator, &denominator);
  if (numerator == 0)
    cout << integer;
  else if (numerator != 0 && integer != 0)
    printf("%ld %ld/%ld", integer, numerator, denominator);
  else
    printf("%ld/%ld", numerator, denominator);
  return 0;
}
