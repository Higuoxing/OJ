#include <iostream>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    int m, row[1001], lut[1001], flag = 0;
    fill(row, row+1001, 0);
    fill(lut, lut+1001, 0);
    scanf("%d", &m);
    for (int j = 1; j <= m; ++ j) {
      int q;
      scanf("%d", &q);
      if (lut[q] > 0)
        flag = 1;
      ++ lut[q];
      row[j] = q;
      for (int k = 1; k <= j; ++ k) {
        if (abs(j - k) == abs(row[j] - row[k]) && j != k)
          flag = 1;
      }
    }
    if (flag)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
