#include <iostream>
#include <string>

using namespace std;

int main() {
  int std_num;
  cin >> std_num;
  string std_names[101];
  string std_nums[101];
  int std_credits[101];

  // store messages
  for (int i = 0; i < std_num; ++ i) {
    string tmp_name;
    string tmp_num;
    int tmp_credit;
    cin >> tmp_name;
    cin >> tmp_num;
    cin >> tmp_credit;
    std_names[tmp_credit] = tmp_name;
    std_nums[tmp_credit] = tmp_num;
    std_credits[tmp_credit] = 991;
  }

  // output max
  for (int i = 100; i > 0; -- i) {
    if (std_credits[i] == 991) {
      cout << std_names[i] << ' ' << std_nums[i] << endl;
      break;
    }
  }

  // output min
  for (int i = 0; i < 101; ++ i) {
    if (std_credits[i] == 991) {
      cout << std_names[i] << ' ' << std_nums[i] << endl;
      break;
    }
  }
  return 0;
}
