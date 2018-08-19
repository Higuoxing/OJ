#include <iostream>
using namespace std;
int main() {
  string s1, s2, lut = "";
  cin >> s1 >> s2;
  int j = 0;
  for (int i = 0; i < s1.length(); ++ i) {
    if (s1[i] == s2[j]) {
      ++ j;
    } else {
      int flag = 0;
      if (islower(s1[i]))
        s1[i] += 'A' - 'a';
      for (int j = 0; j < lut.length(); ++ j) {
        if (s1[i] == lut[j]) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        lut.push_back(s1[i]);
        cout << s1[i];
      }
    }
  }
  return 0;
}
