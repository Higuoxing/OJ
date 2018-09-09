#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  long long n, d;
  int num[100];
  fill(num, num + 100, 0);
  scanf("%lld %lld", &n, &d);
  int idx = 0;
  while (n) {
    num[idx] = n % d;
    ++ idx;
    n /= d;
  }
  int flag = 1;
  for (int i = 0; i < idx; ++ i) {
    if (num[i] != num[idx - i - 1]) {
      flag = 0;
      break;
    }
  }
  if (flag) {
    cout << "Yes\n";
    for (int i = 0; i < idx - 1; ++ i) {
      cout << num[i] << ' ';
    }
    cout << num[idx - 1];
  } else {
    cout << "No\n";
    for (int i = idx - 1; i > 0; -- i) {
      cout << num[i] << ' ';
    }
    cout << num[0];
  }
  return 0;
}
