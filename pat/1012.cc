#include <iostream>
#include <algorithm>
using namespace std;
bool bigger(int a, int b) {
  return a > b;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  string sid[2010];
  int C[2010], M[2010], E[2010], A[2010], all[2010][4];
  for (int i = 0; i < n; ++ i) {
    int c, m, e, a;
    cin >> sid[i] >> c >> m >> e;
    a = (c + m + e) / 3.0 + 0.5;
    C[i] = all[i][0] = c;
    M[i] = all[i][1] = m;
    E[i] = all[i][2] = e;
    A[i] = all[i][3] = a;
  }

  sort(C, C + n, bigger);
  sort(M, M + n, bigger);
  sort(E, E + n, bigger);
  sort(A, A + n, bigger);

  for (int i = 0; i < m; ++ i) {
    string id;
    cin >> id;
    auto found = find(sid, sid+n, id);
    if (found != sid+n) {
      // not found
      auto c = find(C, C+n, all[found-sid][0]) - C + 1;
      auto m = find(M, M+n, all[found-sid][1]) - M + 1;
      auto e = find(E, E+n, all[found-sid][2]) - E + 1;
      auto a = find(A, A+n, all[found-sid][3]) - A + 1;
      if (a <= c && a <= m && a <= e) {
        cout << a << ' ' << 'A' << endl;
      } else if (c <= a && c <= m && c <= e) {
        cout << c << ' ' << 'C' << endl;
      } else if (m <= a && m <= c && m <= e) {
        cout << m << ' ' << 'M' << endl;
      } else if (e <= a && e <= c && e <= m) {
        cout << e << ' ' << 'E' << endl;
      }
    } else {
      cout << "N/A" << endl;
    }
  }

  return 0;
}
