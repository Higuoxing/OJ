#include <iostream>
#include <cmath>
using namespace std;
bool isPrim(int n) {
  int flag = 0;
  int m = (int) sqrt(n);
  for (int i = 2; i < m; ++ i) {
    if (n % i == 0 && i != 1)
      return false;
  }
  return true;
}

int main() {
  int n, d, m = 0;
  while (1) {
    scanf("%d", &n);
    if (n < 0) break;
    scanf("%d", &d);
    while (n) {
      m = 10 * m + n % d;
      n /= d;
    }
    int m_r10 = 0;
    int j = 0;
    while (m) {
      m_r10 += (m % 10) * pow(d, j);
      m /= 10;
      ++ j;
    }
    if (isPrim(m_r10))
      cout << "Yes\n";
    else
      cout << "No\n";

  }
  return 0;
}
