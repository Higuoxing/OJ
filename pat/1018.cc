#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 9999999;

int c, n, s, m,
    graph[510][510],
    st[510], visited[510],
    dis[510];

vector<int> to_here[510];

vector<int> tmp_path, fpath;

int tb = inf, tt = inf;

void dfs(int v) {
  tmp_path.push_back(v);
  if (v == 0) {
    int tmp_tb = 0;
    for (int i = 0; i < tmp_path.size(); ++ i)
      if (tmp_path[i] != 0)
        if (st[tmp_path[i]] < c / 2 || st[tmp_path[i]] > c/2)
          tmp_tb += (st[tmp_path[i]] - c/2);

    if (abs(tmp_tb) < abs(tb)) {
      tb = tmp_tb;
      fpath = tmp_path;
    }
    tmp_path.pop_back();
    return;
  }

  for (int i = 0; i < to_here[v].size(); ++ i)
    dfs(to_here[v][i]);

  tmp_path.pop_back();
}

int main() {

  scanf("%d %d %d %d", &c, &n, &s, &m);
  // init
  fill(graph[0], graph[0] + 510*510, inf);
  fill(dis, dis + 510, inf);
  for (int i = 0; i < n; ++ i) {
    scanf("%d", &st[i+1]);
    graph[i][i] = 0;
  }

  for (int i = 0; i < m; ++ i) {
    int s0, s1, len;
    scanf("%d %d %d", &s0, &s1, &len);
    graph[s0][s1] = graph[s1][s0] = len;
  }

  dis[0] = 0;
  to_here[0].push_back(0);
  for (int i = 0; i < n + 1; ++ i) {
    int minn = inf, v = -1;
    for (int j = 0; j < n + 1; ++ j) {
      if (!visited[j] && dis[j] < minn) {
        minn = dis[j];
        v = j;
      }
    }

    if (v == -1)
      break;
    visited[v] = true;

    for (int j = 0; j < n + 1; ++ j) {
      if (!visited[j] && minn + graph[v][j] < dis[j]) {
        dis[j] = minn + graph[v][j];
        to_here[j].clear();
        to_here[j].push_back(v);
      } else if (!visited[j] && minn + graph[v][j] == dis[j]) {
        to_here[j].push_back(v);
      }
    }
  }

  dfs(s);

  if (tb <= 0)
    printf("%d ", -tb);
  else
    printf("%d ", 0);

  for (int i = fpath.size()-1; i >= 0; -- i) {
    printf("%d", fpath[i]);
    if (i != 0)
      printf("->");
  }

  if (tb >= 0)
    printf(" %d", tb);
  else printf(" %d", 0);

  return 0;
}
