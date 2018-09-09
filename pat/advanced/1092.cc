#include <iostream>
using namespace std;
int main() {
  int color_s[256], color_d[256];
  fill(color_s, color_s+256, 0);
  fill(color_d, color_d+256, 0);
  string c_s, c_d;
  cin >> c_s >> c_d;
  for (int i = 0; i < c_s.length(); ++ i) {
    ++ color_s[(int) c_s[i]];
  }
  for (int i = 0; i < c_d.length(); ++ i) {
    ++ color_d[(int) c_d[i]];
  }
  int flag = 0, sum = 0;
  for (int i = 0; i < 256; ++ i) {
    while (color_d[i] > 0) {
      -- color_s[i];
      -- color_d[i];
    }
    if (color_s[i] < 0)
      flag = 1;
  }
  for (int i = 0; i < 256; ++ i) {
    if (flag) {
      // lack
      if (color_s[i] < 0) sum -= color_s[i];
    } else {
      if (color_s[i] > 0) sum += color_s[i];
    }
  }
  if (flag)
    printf("No %d", sum);
  else
    printf("Yes %d", sum);
  return 0;
}
