#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool increasing(char a, char b) {
  return a < b;
}

bool decreasing(char a, char b) {
  return a > b;
}
int main() {
  string num;
  cin >> num;
  num.insert(0, 4 - num.length(), '0');
  sort(num.begin(), num.end(), increasing);
  int a = stoi(num);
  sort(num.begin(), num.end(), decreasing);
  int b = stoi(num);
  while (b - a != 0 && b - a != 6174) {
    printf("%04d - %04d = %04d\n", b, a, b - a);
    num = to_string(b - a);
    num.insert(0, 4 - num.length(), '0');
    sort(num.begin(), num.end(), increasing);
    a = stoi(num);
    sort(num.begin(), num.end(), decreasing);
    b = stoi(num);
  }
  printf("%04d - %04d = %04d", b, a, b - a);
  return 0;
}
