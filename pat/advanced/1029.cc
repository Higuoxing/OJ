#include <iostream>
using namespace std;

int main() {
  int arr[200002], m, n;
  scanf("%d", &m);
  for (int i = 0; i < m; ++ i) {
    scanf("%d", &arr[i]);
  }
  scanf("%d", &n);
  int k, tcnt = 0, mid = (m + n - 1) / 2;
  for (int i = 0; i < m; ++ i) {
    scanf("%d", &k);
    while (k < arr[i]) {
      tcnt ++;
      if (tcnt == mid) { cout << k; break; }
      scanf("%d", &k);
    }
    ++ tcnt;
    if (tcnt == mid) { cout << arr[i+1]; break; }
  }
  while (tcnt < mid) {
    scanf("%d", &k);
    ++ tcnt;
    if (tcnt == mid) { cout << k; break; }
  }
  return 0;
}

