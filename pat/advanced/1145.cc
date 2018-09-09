#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

bool is_prime(int v) {
  for (int j = 1; j <= sqrt(v); ++ j)
    if (v % j == 0 && j != 1)
      return false;
  return true;
}

int main() {
  int msize, n, m,
      arr[200010];
  scanf("%d %d %d", &msize, &n, &m);
  fill(arr, arr + 200010, -1);
  // find prime
  while (!is_prime(msize))
    ++ msize;

  for (int i = 0; i < n; ++ i) {
    int tmp, flag = -1;
    scanf("%d", &tmp);
    for (int j = 0; j < msize; ++ j) {
      if (arr[(tmp + j*j) % msize] == -1) {
        arr[(tmp + j*j) % msize] = tmp;
        flag = j;
        break;
      }
    }
    if (flag == -1)
      printf("%d cannot be inserted.\n", tmp);
  }

  int cycle = 1;
  for (int i = 0; i < m; ++ i) {
    int tmp;
    scanf("%d", &tmp);
    for (int j = 0; j < msize; ++ j) {
      ++ cycle;
      if (arr[(tmp + j*j) % msize] == tmp ||
          arr[(tmp + j*j) % msize] == -1)
        break;
    }
  }

  printf("%.1f", (float) cycle / m);

  return 0;
}
