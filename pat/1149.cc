#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;
int main() {
  int m, n;
  map<int, set<int> > lut;
  scanf("%d %d", &m, &n);
  for (int i = 0; i < m; ++ i) {
    int s0, s1;
    scanf("%d %d", &s0, &s1);
    lut[s0].insert(s1);
    lut[s1].insert(s0);
  }

  for (int i = 0; i < n; ++ i) {
    set<int> bad_goods;
    int flag = 0;
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; ++ j) {
      int g;
      scanf("%d", &g);
      auto it = bad_goods.find(g);
      if (it != bad_goods.end()) flag = 1;
      else {
        for (auto &q: lut[g])
          bad_goods.insert(q);
      }
    }
    if (flag)
      printf("No\n");
    else
      printf("Yes\n");
  }

  return 0;
}
