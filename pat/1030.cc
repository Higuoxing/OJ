#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::fill;

const int inf = 9999999;
int n, m, s, d,
    graph[500][500],
    cost[500][500], dis[500];

vector<int> pre[500], fpath, tmp_path;

bool visited[500];

int cost_sum = inf, tmp_sum = 0;

void dfs(int v) {
  tmp_path.push_back(v);
  if (v == s) {
    for (int i = 0; i < tmp_path.size() - 1; ++ i) {
      tmp_sum += cost[tmp_path[i]][tmp_path[i+1]];
    }
    if (tmp_sum < cost_sum) {
      fpath = tmp_path;
      cost_sum = tmp_sum;
    }
    tmp_path.pop_back();
    tmp_sum = 0;
    return;
  }
  for (int i = 0; i < pre[v].size(); ++ i)
    dfs(pre[v][i]);
  tmp_path.pop_back();
}

int main() {
  scanf("%d %d %d %d", &n, &m, &s, &d);
  fill(graph[0], graph[0] + 500*500, inf);
  fill(dis, dis + 500, inf);
  fill(visited, visited + 500, false);
  for (int i = 0; i < n; ++ i)
    graph[i][i] = 0;
  for (int i = 0; i < m; ++ i) {
    int s0, s1, len, c;
    scanf("%d %d %d %d", &s0, &s1, &len, &c);
    graph[s0][s1] = graph[s1][s0] = len;
    cost[s0][s1] = cost[s1][s0] = c;
  }

  // start point
  dis[s] = 0;
  pre[s].push_back(s);

  for (int i = 0; i < n; ++ i) {
    int minn = inf, v = -1;
    for (int j = 0; j < n; ++ j) {
      if (!visited[j] && minn > dis[j]) {
        minn = dis[j];
        v = j;
      }
    }

    if (v == -1)
      break;
    visited[v] = true;

    for (int j = 0; j < n; ++ j) {
      if (!visited[j] && minn + graph[v][j] < dis[j]) {
        dis[j] = minn + graph[v][j];
        pre[j].clear();
        pre[j].push_back(v);
      }
      else if (!visited[j] && minn + graph[v][j] == dis[j]) {
        pre[j].push_back(v);
      }
    }
  }

  // for (int i = 0; i < n; ++ i) {
  //   for (int j = 0; j < n; ++ j)
  //     printf("(%07d, %03d) ", graph[i][j], cost[i][j]);
  //   cout << endl;
  // }

  // for (int i = 0; i < n; ++ i) {
  //   printf("(%02d ", dis[i]);
  //   for (int j = 0; j < pre[i].size(); ++ j)
  //     printf("%d ", pre[i][j]);
  //   cout << endl <<  endl;
  // }

  dfs(d);

  for (int i = fpath.size() - 1; i >= 0; -- i)
    cout << fpath[i] << ' ';
  
  cout << dis[d] << ' ' << cost_sum;

  return 0;
}
