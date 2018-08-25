#include <iostream>
using namespace std;
int main() {
  int a, b, len;
  scanf("%d %d", &a, &b);
  string c = to_string(a + b);
  len = c.length();
  for (int i = 0; i < len; ++i) {
    cout << c[i];
    if (c[i] == '-') continue;
    if ((i + 1) % 3 == len % 3 && i != len - 1) cout << ',';
  }
  return 0;
}
