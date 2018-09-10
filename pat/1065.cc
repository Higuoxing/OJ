#include <iostream>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    long long a, b, c, sum;
    scanf("%lld %lld %lld", &a, &b, &c);
    sum = a + b;
    if (a >= 0 && b >= 0 && sum < 0) {
      printf("Case #%d: %s\n", i+1, "true");
    } else if (a <= 0 && b <= 0 && sum >= 0) {
      printf("Case #%d: %s\n", i+1, "false");
    } else if (sum > c) {
      printf("Case #%d: %s\n", i+1, "true");
    } else {
      printf("Case #%d: %s\n", i+1, "false");
    }
  }
}
