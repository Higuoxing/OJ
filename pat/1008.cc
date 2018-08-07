#include <iostream>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int curr_fl = 0, next_fl = 0, t = 0;
  for (int i = 0; i < n; ++ i) {
    scanf("%d", &next_fl);
    if (next_fl > curr_fl) {
      t += 5 + 6*(next_fl - curr_fl);
      curr_fl = next_fl;
    } else {
      t += 5 + 4*(curr_fl - next_fl);
      curr_fl = next_fl;
    }
  }
  printf("%d", t);
  return 0;
}
