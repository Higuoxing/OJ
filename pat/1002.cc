#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int n, ni, cnt = 0;
  float k, a[1001], b[1001];
  fill(a, a+1001, 0);
  fill(b, b+1001, 0);
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%d %f", &ni, &k);
    a[ni] = k;
  }
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%d %f", &ni, &k);
    b[ni] = k;
  }
  for (int i = 0; i < 1001; ++ i) {
    a[i] += b[i];
    if (a[i] != 0) ++ cnt;
  }
  printf("%d", cnt);
  for (int i = 1000; i >= 0; -- i)
    if (a[i] != 0) printf(" %d %.1f", i, a[i]);
  return 0;
}
