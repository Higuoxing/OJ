#include <iostream>
using namespace std;
int main() {
  string s;
  cin >> s;
  long cnt, len = s.length(), 
       cntt = 0, cntp = 0;
  for (int i = 0; i < len; ++ i) {
    if (s[i] == 'T')
      ++ cntt;
  }
  int result = 0;
  for (int i = 0; i < len; ++ i) {
    if (s[i] == 'P') ++ cntp;
    if (s[i] == 'T') -- cntt;
    if (s[i] == 'A') result = (result + (cntp * cntt) % 1000000007) % 1000000007;
  }
  printf("%d", result);
  return 0;
}
