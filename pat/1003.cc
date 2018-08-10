#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int n, m, s, e;
  const int inf = 99999999;
  int vw[510], dis[510], num[510], w[510];
  int g[510][510];
  bool visited[510];

  // init vars
  fill(visited, visited+510, false);
  fill(num, num+510, 0);
  fill(vw, (vw+510), 0);
  fill(w, (w+510), 0);
  fill(g[0], (g[0]+510*510), inf);
  fill(dis, (dis+510), inf);

  scanf("%d %d %d %d", &n, &m, &s, &e);

  for (int i = 0; i < n; ++ i) {
    scanf("%d", &vw[i]);
    g[i][i] = 0;
  }
  for (int i = 0; i < m; ++ i) {
    int v1, v2, d;
    scanf("%d %d %d", &v1, &v2, &d);
    g[v1][v2] = g[v2][v1] = d;
  }

  dis[s] = 0;
  w[s] = vw[s];
  num[s] = 1;
  // traverse all nodes
  for (int i = 0; i < n; ++ i) {

    int minn = inf;
    int v = -1;

    // traverse neighbors
    for (int j = 0; j < n; ++ j) {
      if (!visited[j] && dis[j] < minn) {
        v = j;
        minn = dis[j];
      }
    }

    if (v == -1)
      break;

    visited[v] = true;

    // update path
    for (int j = 0; j < n; ++ j) {
      if (!visited[j] && minn + g[v][j] < dis[j]) {
        dis[j] = minn + g[v][j];
        w[j] = w[v] + vw[j];
        num[j] = num[v];
      } else if (!visited[j] && minn + g[v][j] == dis[j]) {
        dis[j] = minn + g[v][j];
        num[j] += num[v];
        if (w[j] < w[v] + vw[j])
          w[j] = w[v] + vw[j];
      }
    }
  }

  printf("%d %d", num[e], w[e]);

  return 0;
}
