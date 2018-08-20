#include <iostream>
using namespace std;
int main() {
  int m, n, s;
  string winner[1000];
  scanf("%d %d %d", &m, &n, &s);
  int total_cnt = 0, skip_cnt = n - 1;
  if (s > m) {
    cout << "Keep going...";
    return 0;
  }
  for (int i = 0; i < m; ++ i) {
    string fp;
    cin >> fp;
    if (i >= s - 1) {
      // begin
      int flag = 0;
      for (int j = 0; j < total_cnt; ++ j) {
        if (winner[j] == fp)
          // found
          flag = 1;
      }

      if (flag) {
        // win before
      } else {
        if (skip_cnt == n - 1) {
          winner[total_cnt] = fp;
          ++ total_cnt;
          skip_cnt = 0;
          cout << fp << endl;
        } else {
          ++ skip_cnt;
        }
      }
    }
  }
  return 0;
}
