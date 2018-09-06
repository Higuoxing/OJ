#include <algorithm>
#include <iostream>
using namespace std;

int n, m, k,
    graph[1010][1010];
bool visited[1010];

void dfs(int v) {
  visited[v] = true;
  for (int i = 1; i <= n; ++ i)
    if (visited[i] == false && graph[i][v] == 1)
      dfs(i);
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; ++ i) {
    int s0, s1;
    scanf("%d %d", &s0, &s1);
    graph[s0][s1] = graph[s1][s0] = 1;
  }
  for (int i = 0; i < k; ++ i) {
    fill(visited, visited+1010, false);
    int occupy;
    int cnt = 0;
    scanf("%d", &occupy);
    visited[occupy] = true;
    for (int j = 1; j <= n; ++ j) {
      if (!visited[j]) {
        dfs(j);
        ++ cnt;
      }
    }
    printf("%d\n", cnt - 1);
  }
  return 0;
}
