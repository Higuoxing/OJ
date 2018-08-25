#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int inf = 9999999;
int n, m, s, d, l_graph[500][500],
    t_graph[500][500], l_dis[500], t_dis[500];
bool l_visited[500], t_visited[500];


vector<int> l_to_here[500], t_to_here[500],
  t_fpath, l_fpath, l_tmp_path, t_tmp_path;
int l_sum = inf, t_sum = inf,
    l_tmp_sum = 0, t_tmp_sum = 0;
int lt_tmp_sum = 0, lt_sum = inf;
void ldfs(int v) {
  l_tmp_path.push_back(v);
  if (v == s) {
    for (int j = 0; j < l_tmp_path.size() - 1; ++ j) {
      l_tmp_sum += l_graph[l_tmp_path[j+1]][l_tmp_path[j]];
      lt_tmp_sum += t_graph[l_tmp_path[j+1]][l_tmp_path[j]];
    }
    if (l_tmp_sum < l_sum) {
      l_sum = l_tmp_sum;
      l_fpath = l_tmp_path;
      lt_sum = lt_tmp_sum;
    } else if (l_tmp_sum == l_sum && lt_tmp_sum < lt_sum) {
      l_sum = l_tmp_sum;
      l_fpath = l_tmp_path;
      lt_sum = lt_tmp_sum;
    }
    l_tmp_path.pop_back();
    l_tmp_sum = 0;
    lt_tmp_sum = 0;
    return;
  }

  for (int i = 0; i < l_to_here[v].size(); ++ i) {
    ldfs(l_to_here[v][i]);
  }

  l_tmp_path.pop_back();
}

int t_tmp_nodes = 0;
int t_nodes = inf;
void tdfs(int v) {
  t_tmp_path.push_back(v);
  if (v == s) {
    t_tmp_nodes = t_tmp_path.size();
    for (int j = 0; j < t_tmp_path.size() - 1; ++ j) {
      t_tmp_sum += t_graph[t_tmp_path[j+1]][t_tmp_path[j]];
    }
    if (t_tmp_sum < t_sum) {
      t_sum = t_tmp_sum;
      t_fpath = t_tmp_path;
      t_nodes = t_tmp_nodes;
    } else if (t_tmp_sum == t_sum && t_tmp_nodes < t_nodes) {
      t_sum = t_tmp_sum;
      t_fpath = t_tmp_path;
      t_nodes = t_tmp_nodes;
    }
    t_tmp_path.pop_back();
    t_tmp_sum = 0;
    t_tmp_nodes = 0;
    return;
  }

  for (int i = 0; i < t_to_here[v].size(); ++ i) {
    tdfs(t_to_here[v][i]);
  }

  t_tmp_path.pop_back();
}
int main() {
  // init
  fill(l_graph[0], l_graph[0] + 500*500, inf);
  fill(t_graph[0], t_graph[0] + 500*500, inf);
  fill(l_dis, l_dis + 500, inf);
  fill(t_dis, t_dis + 500, inf);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++ i) {
    l_graph[i][i] = 0;
    t_graph[i][i] = 0;
  }
  for (int i = 0; i < m; ++ i) {
    int v1, v2, ow, l, t;
    scanf("%d %d %d %d %d", &v1, &v2, &ow, &l, &t);
    if (ow == 0) {
      l_graph[v1][v2] = l_graph[v2][v1] = l;
      t_graph[v1][v2] = t_graph[v2][v1] = t;
    }
    else {
      l_graph[v1][v2] = l;
      t_graph[v1][v2] = t;
    }
  }
  scanf("%d %d", &s, &d);

  // for (int i = 0; i < n; ++ i) {
  //   for (int j = 0; j < n; ++ j)
  //     printf("%07d ", l_graph[i][j]);
  //   cout << endl;
  // }

  // Dijk algo
  l_dis[s] = 0;
  l_to_here[s].push_back(s);
  t_dis[s] = 0;
  t_to_here[s].push_back(s);
  for (int i = 0; i < n; ++ i) {
    int l_minn = inf, l_v = -1,
        t_minn = inf, t_v = -1;
    for (int j = 0; j < n; ++ j) {
      if (!l_visited[j] && l_dis[j] < l_minn) {
        l_minn = l_dis[j];
        l_v = j;
      }
      if (!t_visited[j] && t_dis[j] < t_minn) {
        t_minn = t_dis[j];
        t_v = j;
      }
    }
    if (l_v != -1) {
      l_visited[l_v] = true;
      for (int j = 0; j < n; ++ j) {
        if (!l_visited[j] && l_minn + l_graph[l_v][j] < l_dis[j]) {
          l_dis[j] = l_minn + l_graph[l_v][j];
          l_to_here[j].clear();
          l_to_here[j].push_back(l_v);
        } else if (!l_visited[j] && l_minn + l_graph[l_v][j] == l_dis[j])
          l_to_here[j].push_back(l_v);
      }
    }
    if (t_v != -1) {
      t_visited[t_v] = true;
      for (int j = 0; j < n; ++ j) {
        if (!t_visited[j] && t_minn + t_graph[t_v][j] < t_dis[j]) {
          t_dis[j] = t_minn + t_graph[t_v][j];
          t_to_here[j].clear();
          t_to_here[j].push_back(t_v);
        } else if (!t_visited[j] && t_minn + t_graph[t_v][j] == t_dis[j])
          t_to_here[j].push_back(t_v);
      }
    }
  }

  // for (int i = 0; i < n; ++ i)
  //   printf("%d ", l_dis[i]);

  // printf("\n");
  // for (int i = 0; i < n; ++ i)
  //   printf("%d ", t_dis[i]);
  //
  ldfs(d);
  tdfs(d);
  if (t_fpath == l_fpath) {
    // same
    printf("Distance = %d; Time = %d:", l_sum, t_sum);
    for (int i = l_fpath.size()-1; i >= 0; -- i) {
      if (i != l_fpath.size()-1)
        printf("->");
      printf(" %d", l_fpath[i]);
      if (i != 0)
        printf(" ");
    }
  } else {
    printf("Distance = %d:", l_sum);
    for (int i = l_fpath.size()-1; i >= 0; -- i) {
      if (i != l_fpath.size()-1)
        printf("->");
      printf(" %d", l_fpath[i]);
      if (i != 0)
        printf(" ");
    }
    printf("\n");
    printf("Time = %d:", t_sum);
    for (int i = t_fpath.size()-1; i >= 0; -- i) {
      if (i != t_fpath.size()-1)
        printf("->");
      printf(" %d", t_fpath[i]);
      if (i != 0)
        printf(" ");
    }
  }

  return 0;
}
