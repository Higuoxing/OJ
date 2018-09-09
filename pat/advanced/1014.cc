#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Customer {
public:
  int rid = 0;
  int ptime = 0; // processing time
  int ftime = 0; // finished time
  int btime = 0; // begin time

  Customer(int rid, int ptime) : rid(rid), ptime(ptime) {}
  ~Customer() = default;
};

int main() {
  int n, m, k, q;
  scanf("%d %d %d %d", &n, &m, &k, &q);
  vector<Customer> customer_queue, fqueue;
  vector<int> counter_time(n, 8 * 3600);
  vector<vector<Customer>> counter_queue(n);
  for (int i = 0; i < k; ++i) {
    int ptime;
    scanf("%d", &ptime);
    customer_queue.push_back(Customer(i + 1, ptime * 60));
  }

  for (int i = 0; i < customer_queue.size(); ++i) {
    int min_counter_size = 11, min_id = -1;
    for (int j = 0; j < counter_time.size(); ++j) {
      if (counter_queue[j].size() < min_counter_size &&
          counter_queue[j].size() < m) {
        // find one
        min_counter_size = counter_queue[j].size();
        min_id = j;
      }
    }

    if (min_id != -1) {
      // find one
      counter_queue[min_id].push_back(customer_queue[i]);
    } else {
      // run one time & push element
      // pop one
      int min_pop_time = 86400, queue_id = -1;
      for (int j = 0; j < counter_time.size(); ++j) {
        if (counter_time[j] + counter_queue[j][0].ptime < min_pop_time) {
          min_pop_time = counter_time[j] + counter_queue[j][0].ptime;
          queue_id = j;
        }
      }

      if (queue_id != -1) {
        counter_queue[queue_id][0].btime = counter_time[queue_id];
        counter_time[queue_id] += counter_queue[queue_id][0].ptime;
        counter_queue[queue_id][0].ftime = counter_time[queue_id];
        fqueue.push_back(counter_queue[queue_id][0]);
        counter_queue[queue_id].erase(counter_queue[queue_id].begin());
        counter_queue[queue_id].push_back(customer_queue[i]);
      } else {
        // just do nothing
        assert(0);
      }
    }
  }

  for (int i = 0; i < counter_queue.size(); ++i) {
    // pop them all
    for (int j = 0; j < counter_queue[i].size(); ++j) {
      counter_queue[i][j].btime = counter_time[i];
      counter_time[i] += counter_queue[i][j].ptime;
      counter_queue[i][j].ftime = counter_time[i];
      fqueue.push_back(counter_queue[i][j]);
    }
  }

  for (int i = 0; i < q; ++i) {
    int id;
    scanf("%d", &id);
    for (int j = 0; j < fqueue.size(); ++j) {
      if (id == fqueue[j].rid) {
        if (fqueue[j].btime < 17 * 3600) {
          int hh = fqueue[j].ftime / 3600, mm = fqueue[j].ftime / 60 - (hh)*60;
          printf("%02d:%02d\n", hh, mm);
        } else
          printf("Sorry\n");
        break;
      }
    }
  }

  return 0;
}
