#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, graph[10010][10010], com_cnt = 0,
    maxheight = 0;
bool visited[10010];
vector<int> temp_path, temp_path_1;
set<int> ss;
void dfs(int v, int level) {
  if (level > maxheight) {
    maxheight = level;
    temp_path.clear();
    temp_path.push_back(v);
  } else if (level == maxheight)
    temp_path.push_back(v);
  visited[v] = true;
  for (int i = 1; i <= n; ++ i) {
    if (!visited[i] && graph[v][i] == 1) {
      dfs(i, level+1);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n-1; ++ i) {
    int s0, s1;
    scanf("%d %d", &s0, &s1);
    graph[s0][s1] = graph[s1][s0] = 1;
  }
  for (int i = 1; i <= n; ++ i) {
    if (!visited[i]) {
      dfs(i, 1);
      ++ com_cnt;
    }
  }
  if (com_cnt >= 2) {
    printf("Error: %d components\n", com_cnt);
    return 0;
  }
  maxheight = 0;
  temp_path_1 = std::move(temp_path);
  fill(visited, visited + 10010, false);
  dfs(temp_path_1[i], 1);
  ss.insert(temp_path_1[i]);
  for (int i = 0; i < temp_path.size(); ++ i) {
    ss.insert(temp_path[i]);
  }
  for (auto &i: ss)
    printf("%d\n", i);
  return 0;
}
