#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n, graph[10010][10010],
    visited[10010], cnt = 0;
vector<int> temp_path;
int maxheight = 0;
void dfs(int v) {
  visited[v] = true;
  for (int i = 1; i <= n; ++ i)
    if (!visited[i] && graph[i][v] == 1)
      dfs(i);
}

void add_path(int node, int level) {
  visited[node] = true;
  if (level > maxheight) {
    maxheight = level;
    temp_path.clear();
    temp_path.push_back(node);
  } else if (level == maxheight) {
    temp_path.push_back(node);
  }
  for (int i = 1; i <= n; ++ i) {
    if (!visited[i] && graph[i][node] == 1)
      add_path(i, level + 1);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++ i) {
    int s0, s1;
    scanf("%d %d", &s0, &s1);
    graph[s0][s1] = graph[s1][s0] = 1;
  }
  fill(visited, visited+10010, false);
  for (int j = 1; j <= n; ++ j) {
    if (!visited[j]) {
      dfs(j);
      ++ cnt;
    }
  }
  if (cnt >= 2) {
    printf("Error: %d components", cnt);
    return 0;
  }

  // traverse
  // find deepest root
  for (int i = 1; i <= n; ++ i) {
    fill(visited, visited+10010, false);
    add_path(i, 1);
  }

  set<int> result;
  for (int i = 0; i < temp_path.size(); ++ i)
    result.insert(temp_path[i]);
  for (auto &i : result)
    printf("%d\n", i);
  return 0;
}
