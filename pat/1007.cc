#include <iostream>
using namespace std;
int main() {
  int n, num[10010];
  int s, e;
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%d", &num[i]);
  }

  int maxx = 0, cur_sum = 0, idx = 0, cur_idx = 0;
  for (int i = 0; i < n; ++ i) {
    cur_sum += num[i];
    if (cur_sum > maxx) {
      idx = cur_idx;
      maxx = cur_sum;
    }
    else if (cur_sum < 0) {
      cur_idx = i + 1;
      cur_sum = 0;
    }
  }

  cout << maxx << idx;
  return 0;

}
