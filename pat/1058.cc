#include <iostream>
using namespace std;
int main() {
  int ga, sa, ka, 
      gb, sb, kb, 
      gc = 0, sc = 0, kc = 0,
      ck = 0, cs = 0;
  scanf("%d.%d.%d", &ga, &sa, &ka);
  scanf("%d.%d.%d", &gb, &sb, &kb);
  kc = (ka + kb) % 29;
  ck = (ka + kb) / 29;
  sc = (ck + sa + sb) % 17;
  cs = (ck + sa + sb) / 17;
  gc = ga + gb + cs;
  printf("%d.%d.%d", gc, sc, kc);
  return 0;
}
