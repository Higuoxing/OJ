#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

class Gang {
public:
  int id;
  int relation_sum = 0;
  int max_relation = 0;
  int max_node;
  std::set<int> mems;
  Gang(int id) : id(id) {}
};

std::vector<Gang> gangs;
std::map<std::string, int> stringToInt;
std::map<int, std::string> intToString;
int n, weight, graph[2010][2010], id = 0, gang_cnt = 0;
bool visited[2010];

void dfs(int v, int id) {
  visited[v] = true;
  int tmp_sum = 0;
  gangs[id].mems.insert(v);
  for (int i = 1; i <= n; ++i) {
    if (graph[v][i] != 0)
      tmp_sum += graph[v][i];
  }
  if (tmp_sum > gangs[id].max_relation) {
    gangs[id].max_relation = tmp_sum;
    gangs[id].max_node = v;
  }
  for (int i = 1; i <= n; ++i) {
    if (graph[i][v] != 0)
      gangs[id].relation_sum += graph[i][v];
    if (!visited[i] && graph[i][v] > 0) {
      gangs[id].mems.insert(i);
      dfs(i, id);
    }
  }
}

int main() {
  scanf("%d %d", &n, &weight);
  for (int i = 0; i < n; ++i) {
    std::string s0, s1;
    int w;
    std::cin >> s0 >> s1 >> w;
    if (stringToInt[s0] == 0) {
      stringToInt[s0] = id;
      intToString[id] = s0;
      ++id;
    }
    if (stringToInt[s1] == 0) {
      stringToInt[s1] = id;
      intToString[id] = s1;
      ++id;
    }
    graph[stringToInt[s0]][stringToInt[s1]] += w;
    graph[stringToInt[s1]][stringToInt[s0]] += w;
  }

  std::vector<Gang> result;
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      gangs.push_back(Gang(gang_cnt));
      dfs(i, gang_cnt);
      if (gangs[gang_cnt].mems.size() > 2 &&
          gangs[gang_cnt].relation_sum > 2 * weight)
        result.push_back(gangs[gang_cnt]);
      ++gang_cnt;
    }
  }

  // for (int i = 0; i < gangs.size(); ++ i)
  //   printf("%d\n", gangs[i].relation_sum);
  printf("%lu\n", result.size());

  std::sort(result.begin(), result.end(), ([](Gang g0, Gang g1) {
              return intToString[g0.max_node] < intToString[g1.max_node];
            }));

  for (int i = 0; i < result.size(); ++i) {
    printf("%s %lu\n", intToString[result[i].max_node].c_str(),
           result[i].mems.size());
  }

  return 0;
}
