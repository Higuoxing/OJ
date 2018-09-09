#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
bool is_prime(long long v) {
  if (v <= 1) return false;
  for (long long i = 1; i*i <= v; ++ i)
    if (v % i == 0 && i != 1)
      return false;
  return true;
}
int main() {
  while (1) {
    long long m, n;
    scanf("%lld %lld", &m, &n);
    if (m < 0) break;
    if (!is_prime(m)) {
      printf("No\n");
      continue;
    }
    vector<long long> s;
    while (m) {
      s.push_back(m % n);
      m /= n;
    }
    long long q = 0;
    for (int i = s.size() - 1; i >= 0; -- i)
      q += s[i] * pow(n, s.size() - i - 1);
    printf("%s", is_prime(q) ? "Yes\n": "No\n");
  }
  return 0;
}
