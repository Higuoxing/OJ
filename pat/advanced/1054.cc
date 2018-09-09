#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main() {
  int pix[800*600], m, n, idx = 0;
  map<int, int> lut;
  fill(pix, pix + 800 * 600, 0);
  scanf("%d %d", &m, &n);
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < m; ++ j) {
      int color;
      scanf("%d", &color);
      auto p = lut.find(color);
      if (p == lut.end()) {
        lut[color] = idx;
        ++ idx;
      } else {
        ++ pix[p -> second];
      }
    }
  }
  
  int maxx = -1;
  int max_pix = -1;
  for (auto &it: lut) {
    if (pix[it.second] > maxx) {
      max_pix = it.first;
      maxx = pix[it.second];
    }
  }
  cout << max_pix;

  return 0;
}
