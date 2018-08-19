#include <iostream>
#include <string>
using namespace std;
int main() {
  int n;
  string s, ans;
  scanf("%d\n", &n);
  getline(cin, ans);
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < n - 1; ++ i) {
    getline(cin, s);
    reverse(s.begin(), s.end());
    int len = min(s.length(), ans.length());
    int flag = ans.length();
    for (int j = 0; j < len; ++ j) {
      if (ans[j] != s[j]) {
        flag = j;
        break;
      }
    }
    ans = ans.substr(0, flag);
  }
  if (ans.length() > 0)
    for (int i = ans.length() - 1; i >= 0; -- i)
      cout << ans[i];
  else
    cout << "nai";
  return 0;
}
