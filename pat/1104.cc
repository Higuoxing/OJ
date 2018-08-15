#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int n;
  double sum = 0.0, eles[100010];
  scanf("%d", &n);
  fill(eles, eles + 100010, 0.0);
  for (int i = 0; i < n; ++ i) {
    cin >> eles[i];
    sum +=  (i + 1) * (n - i) * eles[i] ;
  }

  printf("%.2f", sum);
  return 0;
}
