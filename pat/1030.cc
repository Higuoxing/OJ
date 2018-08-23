#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::fill;

int main() {
  int n, m, s, d,
      dis[500], visited[500],
      g[500][500], cost[500],
      cos_map[500][500],
      p[500][500];
  const int inf = 999999;
  scanf("%d %d %d %d", &n, &m, &s, &d);
  // initialize everything
  fill(g[0], g[0] + 500*500, inf);
  fill(cos_map[0], cos_map[0] + 500*500, inf);
  fill(dis, dis+500, inf);
  fill(visited, visited+500, false);
  fill(cost, cost+500, 0);
  fill(p[0], p[0]+500*500, -1);
  for (int i = 0; i < n; ++ i) {
    g[i][i] = 0;
    cos_map[i][i] = 0;
  }
  // read map
  for (int i = 0; i < m; ++ i) {
    int start, end, len, c;
    scanf("%d %d %d %d", &start, &end, &len, &c);
    g[start][end] = len;
    g[end][start] = len;
    cos_map[start][end] = c;
    cos_map[end][start] = c;
  }

  dis[s] = 0;
  cost[s] = 0;

  for (int i = 0; i < n; ++ i) {
    int minn = inf, v = -1,
        c = 0;
    for (int j = 0; j < n; ++ j) {
      if (!visited[j] && dis[j] < minn) {
        minn = dis[j];
        v = j;
        c = cost[j];
      }
    }
    
    if (v == -1)
      break;

    visited[v] = true;

    for (int j = 0; j < n; ++ j) {
      if (!visited[j] && minn + g[v][j] < dis[j]) {
        dis[j] = minn + g[v][j];
      }
    }
  }

  for (int i = 0; i < n; ++ i) {
    cout << dis[i] << ' ' << cost[i] << endl;
  }

  return 0;
}
