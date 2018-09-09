#include <iostream>
#include <vector>
using namespace std;

class Customer {
public:
  int arrive_time = 0;
  int occupied_time = 0;
  int wait_time = 0;
  bool visited = false;

  Customer() = default;
  Customer(int arrive_time, int occupied_time)
      : arrive_time(arrive_time), occupied_time(occupied_time) {}
  ~Customer() = default;
};

int main() {
  int n, m;
  vector<Customer> customerQueue;
  scanf("%d %d", &n, &m);
  vector<int> serv(m, 8 * 3600);
  for (int i = 0; i < n; ++i) {
    int hh, mm, ss, tt, sec;
    scanf("%d:%d:%d %d", &hh, &mm, &ss, &tt);
    sec = ss + 60 * (mm + 60 * hh);
    if (sec >= 17 * 3600)
      continue;
    customerQueue.push_back(Customer(sec, tt * 60));
  }

  for (int i = 0; i < customerQueue.size(); ++i) {
    int min_time = 86400, arrive_idx = -1;
    for (int j = 0; j < customerQueue.size(); ++j) {
      if (customerQueue[j].arrive_time < min_time && // arive early
          customerQueue[j].visited == false /* not visited */) {
        min_time = customerQueue[j].arrive_time;
        arrive_idx = j;
      }
    }

    if (arrive_idx == -1)
      break;

    int min_serv = 86400, serv_idx = -1;
    for (int j = 0; j < serv.size(); ++j) {
      if (min_serv > serv[j] && serv[j] <= 17 * 3600) {
        min_serv = serv[j];
        serv_idx = j;
      }
    }

    if (serv_idx == -1)
      break;

    // visit
    customerQueue[arrive_idx].visited = true;
    customerQueue[arrive_idx].wait_time =
        (min_serv > customerQueue[arrive_idx].arrive_time)
            ? min_serv - customerQueue[arrive_idx].arrive_time
            : 0;
    serv[serv_idx] =
        (customerQueue[arrive_idx].arrive_time > serv[serv_idx])
            ? customerQueue[arrive_idx].occupied_time +
                  customerQueue[arrive_idx].arrive_time
            : customerQueue[arrive_idx].occupied_time + serv[serv_idx];
  }

  double sum = 0.0;
  int cnt = 0;
  for (auto &c : customerQueue) {
    if (c.visited) {
      sum += c.wait_time;
      ++cnt;
    }
  }

  if (cnt == 0)
    printf("0.0");
  else
    printf("%.1f", (double)sum / 60.0 / cnt);
  return 0;
}
