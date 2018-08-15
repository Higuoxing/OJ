#include <iostream>
#include <string>
using namespace std;
int main() {
  string s1, s2;
  bool lut[256];
  fill(lut, lut + 256, false);
  getline(cin, s1);
  getline(cin, s2);
  for (int i = 0; i < s2.length(); ++ i) {
    lut[(int) (s2[i])] = true;
  }

  for (int i = 0; i < s1.length(); ++ i) {
    if (!lut[(int) s1[i]]) {
      cout << s1[i];
    }
  }
  return 0;
}
