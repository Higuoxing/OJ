#include <iostream>
#include <algorithm>
using namespace std;
long long to_r10(string s, long long r) {
  long long res = 0;
  for (auto &i: s) {
    int digit = 0;
    if (i >= '0' && i <= '9') {
      digit = i - '0';
    } else if (i >= 'a' && i <= 'z') {
      digit = i - 'a' + 10;
    }
    res *= r;
    res += digit;
  }
  return res;
}

long long find_radix(string s, long long target) {
  long long low = 0;
  for (auto &i: s) {
    if (isdigit(i) && i - '0' > low)
      low = i - '0' + 1;
    else if (isalpha(i) && i - 'a' + 10 > low)
      low = i - 'a' + 11;
  }
  long long high = max(low, target);
  while (low <= high) {
    long long mid = (low + high) / 2;
    long long cal = to_r10(s, mid);
    if (cal > target || cal < 0)
      high = mid - 1;
    else if (cal == target)
      return mid;
    else
      low = mid + 1;
  }
  return -1;
}

int main() {
  long long tag, r;
  string s1, s2;
  cin >> s1 >> s2 >> tag >> r;
  long long r_find = (tag == 1) ? find_radix(s2, to_r10(s1, r)): find_radix(s1, to_r10(s2, r));
  if (r_find != -1)
    printf("%lld", r_find);
  else
    printf("Impossible");
  return 0;
}
