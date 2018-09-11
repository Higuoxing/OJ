#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 999999;
int m, n, s, e,
    teams[501], dis[501], vw[501] = { 0 },
    graph[501][501], nums[501];
bool visited[501] = { false };
int main() {
  scanf("%d %d %d %d", &m, &n, &s, &e);
  fill(graph[0], graph[0]+501*501, inf);
  fill(dis, dis+501, inf);
  for (int i = 0; i < m; ++ i) scanf("%d", &teams[i]);
  for (int i = 0; i < n; ++ i) {
    int s0, s1, d;
    scanf("%d %d %d", &s0, &s1, &d);
    graph[s0][s1] = graph[s1][s0] = d;
  }
  nums [s] = 1;
  dis  [s] = 0;
  vw   [s] = teams[s];
  for (int i = 0; i < m; ++ i) {
    int minn = inf, v = -1;
    for (int j = 0; j < m; ++ j) {
      if (!visited[j] && dis[j] < minn) {
        minn = dis[j];
        v = j;
      }
    }
    if (v == -1) break;
    visited[v] = true;
    for (int j = 0; j < m; ++ j) {
      if (!visited[j] && graph[v][j] + minn < dis[j]) {
        dis[j] = minn + graph[v][j];
        vw[j] = vw[v] + teams[j];
        nums[j] = nums[v];
      } else if (!visited[j] && graph[v][j] + minn == dis[j]) {
        nums[j] += nums[v];
        if (vw[j] < vw[v] + teams[j])
          vw[j] = vw[v] + teams[j];
      }
    }
  }
  printf("%d %d", nums[e], vw[e]);
  return 0;
}
