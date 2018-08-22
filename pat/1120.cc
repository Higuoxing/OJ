#include <iostream>
using namespace std;
int main() {
  int n, ids[37], cnt = 0;
  fill(ids, ids+37, 0);
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    int sum = 0;
    string num;
    cin >> num;
    for (int j = 0; j < num.length(); ++ j) {
      sum += (int) num[j] - '0';
    }
    ++ ids[sum];
    if (ids[sum] == 2)
      ++ cnt;
  }
  printf("%d\n", cnt);
  for (int i = 0; i < 37; ++ i) {
    if (ids[i] >= 2) {
      printf("%d", i);
      -- cnt;
      if (cnt != 0)
        printf(" ");
    }
  }
  return 0;
}
