#include <iostream>
using namespace std;
void copy_array(int *a, int *b, int n) {
  for (int i = 0; i < n; ++ i) {
    b[i] = a[i];
  }
}
int main() {
  int n, order_n[54], order_o[54], pos[54];
  char color[5] = { 'S', 'H', 'C', 'D', 'J' };
  // initial order array
  for (int i = 0; i < 54; ++ i) {
    order_n[i] = i;
  }
  copy_array(order_n, order_o, 54);

  // read tests
  scanf("%d", &n);

  for (int i = 0; i < 54; ++ i)
    scanf("%d", &pos[i]);

  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < 54; ++ j) {
      // update for order_o[j]
      for (int k = 0; k < 54; ++ k) {
        if (pos[k] == j + 1) {
          // find pos
          order_n[j] = order_o[k];
          break;
        }
      }
    }
    copy_array(order_n, order_o, 54);
  }

  for (int i = 0; i < 54; ++ i) {
    printf("%c%d", color[(int) order_n[i] / 13], order_n[i] % 13 + 1);
    if (i != 53)
      printf(" ");
  }
  return 0;
}
