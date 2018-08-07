#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;
int main() {
  string s0, s1, s2, s3;
  cin >> s0 >> s1 >> s2 >> s3;
  int lop0 = min(s0.length(), s1.length());
  int lop1 = min(s2.length(), s3.length());
  int h, m;
  string D[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
  for (int i = 0; i < lop0; ++ i) {
    if (s0[i] >= 'A' && s0[i] <= 'G' && s0[i] == s1[i]) {
      cout << D[(int)s0[i]-'A'] << ' ';
      for (int j = i+1; j < lop0; ++ j) {
        if (s0[j] >= 'A' && s0[j] <= 'N' && s0[j] == s1[j]) {
          h = (int)(10 + s0[j] - 'A');
          break;
        }
        else if (isdigit(s0[j]) && s0[j] == s1[j]) {
          h = (int)(s0[j] - '0');
          break;
        }
      }
      break;
    }
  }
  for (int i = 0; i < lop1; ++ i) {
    if (isalpha(s2[i]) && s2[i] == s3[i]) {
      m = i;
      break;
    }
  }
  printf("%02d:%02d", h, m);
  return 0;
}
