#include <iostream>
#include <string>
using namespace std;
int main() {
  string inp;
  cin >> inp;
  int N = inp.length();
  int M = (N + 8)/3;
  int m = (N + 2)/3;
  int b = 0, l = 0;
  for (int i = M; i >= m; -- i) {
    if ((N+i)%2 == 0 && (N+2-i) % 2 == 0 && (N+2-i)/2 + 1 > i - 2) {
      if (i >= b) {
        b = i;
      }
    }
  }
  l = (N + 2 -b) / 2;
  for (int i = 0; i < l - 1; ++ i) {
    printf("%c", inp[i]);
    for (int j = 0; j < b-2; ++ j) {
      printf(" ");
    }
    printf("%c\n", inp[inp.length()-1-i]);
  }
  for (int i = 0; i < b; ++ i) {
    printf("%c", inp[l-1+i]);
  }
  return 0;
}
