#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> rates;
  for (int i = 0; i < 24; ++ i) {
    int r;
    scanf("%d", &r);
    rates.push_back(r);
  }

  return 0;
}
