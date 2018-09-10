#include <iostream>
using namespace std;
int main() {
  int d;
  char radix_13[14] = "0123456789ABC";
  printf("#");
  for (int i = 0; i < 3; ++ i) {
    scanf("%d", &d);
    printf("%c%c", radix_13[d/13], radix_13[d%13]);
  }
  return 0;
}
