#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int arr[1010];
  fill(arr, arr+1010, 0);
  for (int i = 0; i < n; ++ i) {
    int val;
    scanf("%d", &val);
    arr[val] += 1;
  }

  int flag = 0;
  for (int j = 1; j <= m / 2 + 1; ++ j) {
    if (arr[j] != 0) {
      arr[j] -= 1;
      if (arr[m - j] != 0) {
        flag = 1;
        printf("%d %d", j, m-j);
        break;
      }
      arr[j] += 1;
    }
  }
  if (flag == 0)
    printf("No Solution");
  return 0;
}
