#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  const int inf = 999999;
  int n, m, k, sr;
  int g[1020][1020], dis[10][1020];
  fill(g[0], g[0] + 1020*1020, inf);
  fill(dis[0], dis[0]+10*1020, inf);
  scanf("%d %d %d %d", &n, &m, &k, &sr);

  for (int i = 0; i < k; ++ i) {
    string p0, p1;
    int p0_i, p1_i, d;
    cin >> p0 >> p1 >> d;

    if (p0[0] == 'G') {
      // this is gas station
      p0 = p0.substr(1);
      p0_i = n + stoi(p0) - 1;
    } else {
      p0_i = stoi(p0) - 1;
    }

    if (p1[0] == 'G') {
      // this is gas station
      p1 = p1.substr(1);
      p1_i = n + stoi(p1) - 1;
    } else {
      p1_i = stoi(p1) - 1;
    }

    g[p0_i][p1_i] = g[p1_i][p0_i] = d;
  }

  // Gas station: G(k) = n + k - 1;
  // House: H(k) = k - 1;
  // traverse stations
  for (int i = 0; i < m; ++ i) {
    bool visited[1020];
    fill(visited, visited + 1020, false);
    dis[i][n+i] = 0;
    // traverse all nodes
    for (int j = 0; j < m + n; ++ j) {
      int minn = inf;
      int v = -1;
      // traverse neighbors
      for (int k = 0; k < m + n; ++ k) {
        if (!visited[k] && dis[i][k] < minn) {
          v = k;
          minn = dis[i][k];
        }
      }

      if (v == -1)
        break;
      visited[v] = true;

      // update paths
      for (int k = 0; k < m + n; ++ k) {
        if (!visited[k] && minn + g[v][k] < dis[i][k]) {
          dis[i][k] = minn + g[v][k];
        }
      }
    }
  }

  int max_min = inf;
  int min_max = 0;
  int flag = 0;
  int loc = 0;
  for (int i = 0; i < m; ++ i) {

    int sr_flag = 1;
    int sum = 0, minn = inf;
    for (int j = 0; j < n; ++ j) {
      if (dis[i][j] > sr) {
        sr_flag = 0;
        break;
      }

      if (dis[i][j] < minn)
        minn = dis[i][j];
      sum += dis[i][j];
    }

    if (sr_flag == 1 && minn > min_max) {
      min_max = minn;
      max_min = sum;
      loc = i;
    } else if (sr_flag == 1 && minn == min_max) {
      if (sum < max_min) {
        max_min = sum;
        loc = i;
      }
    }

    if (sr_flag == 1) {
      flag = 1;
    }
  }

  if (flag == 0) {
    printf("No Solution");
  } else {
    printf("G%d\n%.1f %.1f", loc+1, (float)min_max, (float)(max_min)/(float)(n) + 0.05);
  }

  return 0;
}
