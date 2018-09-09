#include <iostream>

int main() {
  int counter = 0;
  int n;
  std::cin >> n;
  while (n != 1) {
    if (n % 2 == 0) {
      n = n / 2;
      ++ counter;
    } else {
      n = (3 * n + 1) / 2;
      ++ counter;
    }
  }
  std::cout << counter;
  return 0;
}
