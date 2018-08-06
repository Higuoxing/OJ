#include <iostream>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int minc = 864000;
  int maxl = 0;
  string f, l;
  for (int i = 0; i < n; ++ i) {
    string name;
    cin >> name;
    int ch, cm, cs, lh, lm, ls;
    scanf("%d:%d:%d %d:%d:%d", &ch, &cm, &cs, &lh, &lm, &ls);
    int com = ch*3600 + cm*60 + cs;
    int lev = lh*3600 + lm*60 + ls;
    if (com < minc) {
      f = name;
      minc = com;
    }
    if (lev > maxl) {
      l = name;
      maxl = lev;
    }
  }
  cout << f << ' ' << l;
  return 0;
}
