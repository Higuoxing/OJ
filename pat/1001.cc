#include <iostream>
using namespace std;
int main() {
  long a, b;
  scanf("%ld %ld", &a, &b);
  string c = to_string(a + b);
  size_t len = c.length();
  for (int i = 0; i < len; ++ i) {
    printf("%c", c[i]);
    if (c[i] == '-') continue;
    if ((len - i) % 3 == 1 && i != len - 1) printf("%c", ',');
  }
  return 0;
}
