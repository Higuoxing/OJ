#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int n, m, len[100010], sum = 0;
  scanf("%d", &n);
  fill(len, len+100010, 0);
  for (int i = 0; i < n; ++ i) {
    int tmp_len;
    scanf("%d", &tmp_len);
    sum += tmp_len;
    len[i] = tmp_len;
  }

  scanf("%d", &m);
  for (int i = 0; i < m; ++ i) {
    int s, e, tmp_s, tmp_e, tmp_path = 0;
    scanf("%d %d", &s, &e);
    tmp_s = min(s - 1, e - 1);
    tmp_e = max(s - 1, e- 1);
    for (int j = tmp_s; j < tmp_e; ++ j) {
      tmp_path += len[j];
    }

    printf("%d\n", min(tmp_path, sum - tmp_path));
  }

  return 0;
}
