#include <iostream>
using namespace std;
int to_r10(char c) {
  if (c - 'a' >= 0) {
    return (int)(10 + c - 'a');
  } else return (int)(c - '0');
}

int main() {
  string num[2];
  int id, r;
  cin >> num[0] >> num[1] >> id >> r;
  int given = 0;
  int cal = 0;
  for (int i = 0; i < num[id-1].length(); ++ i) {
    given *= r;
    given += to_r10(num[id-1][i]);
  }
  int cal_r = 0;
  int j = 0;
  while (cal > given) {
    cal = 0;
    for (int i = 0; i < num[2-id].length(); ++ i) {
      cal *= j;
      cal += to_r10(num[2-id][i]);
    }
    if (cal == given) {
      cal_r = j;
      break;
    }
  }
  if (cal_r != 0) {
    cout << cal_r;
  } else {
    cout << "Impossible";
  }
  return 0;
}
