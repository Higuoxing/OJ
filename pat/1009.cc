#include <iostream>
using namespace std;
int main() {
  float a[1001] = { 0 };
  float c[2001] = { 0 };
  int n;
  scanf("%d", &n);
  // store poly a
  for (int i = 0; i < n; ++ i) {
    int idx;
    float coeff;
    scanf("%d %f", &idx, &coeff);
    a[idx] = coeff;
  }
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    int idx;
    float coeff;
    scanf("%d %f", &idx, &coeff);
    for (int j = 0; j < 1001; ++ j) {
      c[idx + j] += coeff * a[j];
    }
  }
  int cnt = 0;
  for (int i = 0; i < 2001; ++ i) {
    if (c[i] != 0.0)
      ++ cnt;
  }
  cout << cnt;
  for (int i = 2000; i >= 0; -- i) {
    if (c[i] != 0.0)
      printf(" %d %.1f", i, c[i]);
  }
  return 0;
}
