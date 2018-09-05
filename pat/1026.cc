#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Pair {
public:
  bool is_vip;
  int arriving_time;
  int playing_time;
  int Leaving_time;

  Pair(bool is_vip, int arriving_time, int playing_time)
      : is_vip(is_vip), arriving_time(arriving_time),
        playing_time(playing_time) {}
  ~Pair() = default;
  friend bool operator<(Pair p0, Pair p1) {
    return p0.arriving_time < p1.arriving_time;
  }
  friend bool operator>(Pair p0, Pair p1) {
    return p0.arriving_time > p1.arriving_time;
  }
  friend bool operator==(Pair p0, Pair p1) {
    return p0.arriving_time == p1.arriving_time;
  }
};

class Table {
public:
  bool is_vip;
  int current_time = 8 * 3600;

  Table() = default;
  ~Table() = default;

  bool is_closed() { return current_time >= 21 * 3600; }
};

int main() {
  int m, n, k;
  vector<Pair> waiting_queue;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    int hh, mm, ss, pm, is_vip, arriving_time;
    scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &pm, &is_vip);
    arriving_time = hh * 3600 + mm * 60 + ss;
    waiting_queue.push_back(Pair(is_vip, arriving_time, pm));
  }

  sort(waiting_queue.begin(), waiting_queue.end());

  for (int i = 0; i < waiting_queue.size(); ++i) {
    printf("%d\n", waiting_queue[i].arriving_time);
  }

  scanf("%d %d", &m, &k);
  vector<Table> tables(m + k);

  for (int i = 0; i < k; ++i) {
    int tb_id;
    scanf("%d", &tb_id);
    tables[tb_id].is_vip = true;
  }

  for (int i = 0; i < waiting_queue.size(); ++ i) {
  }

  return 0;
}
