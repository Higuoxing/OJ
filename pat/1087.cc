#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::fill;
using std::pair;
using std::map;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

const int inf = 9999999;
int graph[200][200],
    joy[200], dis[200];
bool visited[200];
vector<int> to_here[200];
vector<int> tmp_path, fpath;

int max_happ = -1, city_cnt = 0;
int min_path_cnt = 0;

void dfs(int v) {
  int tmp_happ = 0, tmp_cnt = 0;
  tmp_path.push_back(v);
  if (v == 0) {
    ++ min_path_cnt;
    tmp_cnt = tmp_path.size();
    for (int i = 0; i < tmp_path.size(); ++ i) {
      tmp_happ += joy[tmp_path[i]];
    }
    if (tmp_happ > max_happ) {
      city_cnt = tmp_cnt;
      max_happ = tmp_happ;
      fpath = tmp_path;
    } else if (tmp_happ == max_happ && (tmp_happ / tmp_cnt) > (max_happ / city_cnt)) {
      city_cnt = tmp_cnt;
      max_happ = tmp_happ;
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
  int n, m, e;
  string s;
  fill(graph[0], graph[0] + 200*200, inf);
  fill(visited, visited + 200, false);
  fill(dis, dis + 200, inf);
  cin >> n >> m >> s;
  map<string, int> nlut = { { s, 0 } };
  for (int i = 0; i < n; ++ i) {
    graph[i][i] = 0;
  }
  for (int i = 1; i < n; ++ i) {
    string name;
    int hap;
    cin >> name >> hap;
    if (name == "ROM")
      e = i;
    nlut.insert(pair<string, int>({ name, i }));
    joy[i] = hap;
  }

  for (int i = 0; i < m; ++ i) {
    string s0, s1;
    int c;
    cin >> s0 >> s1 >> c;
    auto ss = nlut.find(s0);
    auto se = nlut.find(s1);
    graph[ss->second][se->second] = 
      graph[se->second][ss->second] = c;
  }
  
  dis[0] = 0;
  to_here[0].push_back(0);
  for (int i = 0; i < n; ++ i) {
    int minn = inf, v = -1;
    for (int j = 0; j < n; ++ j) {
      if (!visited[j] && dis[j] < minn) {
        v = j;
        minn = dis[j];
      }
    }

    if (v == -1)
      break;
    visited[v] = true;

    for (int j = 0; j < n; ++ j) {
      if (!visited[j] && minn + graph[v][j] < dis[j]) {
        // update path
        dis[j] = minn + graph[v][j];
        to_here[j].clear();
        to_here[j].push_back(v);
      } else if (!visited[j] && minn + graph[v][j] == dis[j]) {
        to_here[j].push_back(v);
      }
    }
  }

  dfs(e);

  cout << min_path_cnt << ' '
       << dis[e]       << ' '
       << max_happ     << ' '
       << (max_happ / (fpath.size()-1)) << endl;

  for (int i = fpath.size() - 1; i >= 0; -- i) {
    for (auto it = nlut.begin(); it != nlut.end(); ++ it) {
      if (it -> second == fpath[i])
        cout << it -> first;
    }
    if (i != 0)
      cout << "->";
  }
  /// print to_here array
  // for (int i = 0; i < n; ++ i) {
  //   for (int j = 0; j < to_here[i].size(); ++ j)
  //     printf("%d ", to_here[i][j]);
  //   cout << endl;
  // }

  // for (int i = 0; i < n; ++ i) {
  //   printf("%d ", dis[i]);
  // }
  // cout << endl;

  // for (int i = 0; i < n; ++ i) {
  //   for (int j = 0; j < n; ++ j) {
  //     printf("%07d ", graph[i][j]);
  //   }
  //   cout << joy[i] << ' ' << endl;
  // }

  return 0;
}
