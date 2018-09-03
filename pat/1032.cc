#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  vector<int> lut(100010, -2);
  int w1, w2, n;
  scanf("%d %d %d", &w1, &w2, &n);
  for (int i = 0; i < n; ++ i) {
    char c;
    int s1, s2;
    scanf("%d %c %d", &s1, &c, &s2);
    lut[s1] = s2;
  }

  // travel
  set<int> letters;
  int cursor = w1;
  while (lut[cursor] != -1) {
    letters.insert(cursor);
    cursor = lut[cursor];
  }

  cursor = w2;
  int common = -2;
  while (lut[cursor] != -1) {
    auto it = letters.find(cursor);
    if (it != letters.end()) {
      common = cursor;
      break;
    }
    if (cursor >= 0 && cursor < lut.size())
      cursor = lut[cursor];
    else if (cursor == -1)
      break;
  }
  
  if (common != -1 && common != -2)
    printf("%05d", common);
  else
    printf("-1");

  return 0;
}
