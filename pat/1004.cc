#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
  int n, m;
  int graph[110][110];
  int depth[110];
  int cnt[110];
  fill(graph[0], graph[0] + 110*110, -1);
  fill(depth, depth + 110, -1);
  fill(cnt, cnt + 110, 0);
  scanf("%d %d", &n, &m);
  
  if (n == 1) {
    cout << '1';
    return 0;
  }
  
  for (int i = 0; i < m; ++ i) {
    string id, child;
    int k, id_i, child_i;
    cin >> id >> k;
    id_i = stoi(id);
    for (int j = 0; j < k; ++ j) {
      cin >> child;
      child_i = stoi(child);
      graph[id_i - 1][child_i - 1] = 1;
    }
  }

  depth[0] = 0;
  int maxx_dep = 0;
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      if (graph[i][j] != -1) {
        depth[j] = depth[i] + 1;
        if (maxx_dep < depth[j])
          maxx_dep = depth[j];
        int flag = 1;
        for (int k = 0; k < n; ++ k) {
          if (graph[j][k] == -1)
            continue;
          flag = 0;
          break;
        }
        if (flag == 1)
          ++ cnt[depth[j]];
      }
    }
  }

  for (int i = 0; i < maxx_dep; ++ i) {
    cout << cnt[i] << ' ';
  }
  cout << cnt[maxx_dep];

  return 0;
}
