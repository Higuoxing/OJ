#include <iostream>
using namespace std;
int main() {
  int n;
  int lottery[10001] = { 0 };
  int order[100001] = { 0 };
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    int bet;
    scanf("%d", &bet);
    ++ lottery[bet-1];
    order[i] = bet-1;
  }
  int flag = 0;
  for (int i = 0; i < 100001; ++ i) {
    if (lottery[order[i]] == 1) {
      cout << order[i] + 1 << endl;
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    cout << "None";
  }
  return 0;
}
