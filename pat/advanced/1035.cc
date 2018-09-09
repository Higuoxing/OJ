#include <iostream>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int cnt = 0;
  string ts[1001], pwds[1001];
  for (int i = 0; i < n; ++ i) {
    string t, pwd;
    cin >> t >> pwd;
    int flag = 0;
    for (int j = 0; j < pwd.length(); ++ j) {
      if (pwd[j] == '1') {
        pwd[j] = '@';
        flag = 1;
      } else if (pwd[j] == '0') {
        pwd[j] = '%';
        flag = 1;
      } else if (pwd[j] == 'l') {
        pwd[j] = 'L';
        flag = 1;
      } else if (pwd[j] == 'O') {
        pwd[j] = 'o';
        flag = 1;
      }
    }
    if (flag == 1) {
      ts[cnt] = t;
      pwds[cnt] = pwd;
      ++ cnt;
    }
  }
  if (cnt == 0 && n != 1) {
    printf("There are %d accounts and no account is modified", n);
  } else if (n != 1) {
    cout << cnt << endl;
    for (int i = 0; i < cnt; ++ i) {
      cout << ts[i] << ' ' << pwds[i] << '\n';
    }
  } else if (n == 1) {
    printf("There is 1 account and no account is modified");
  }

  return 0;
}
