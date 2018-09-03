#include <iostream>
using namespace std;

int n, graph[10001][10001];

int dfs(int v) {

}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++ i) {
    int c, r;
    scanf("%d %d", &c, &r);
    graph[c][r] = graph[r][c] = 1;
  }

  return 0;
}
