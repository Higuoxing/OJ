#include <iostream>
using namespace std;
int main() {
  float prod = 1.0;
  char stat[3] = { 'W', 'T', 'L' };
  for (int i = 0; i < 3; ++ i) {
    float prob = 0.0;
    int idx = 0;
    for (int j = 0; j < 3; ++ j) {
      float curr_prob;
      scanf("%f", &curr_prob);
      if (curr_prob >= prob) {
        prob = curr_prob;
        idx = j;
      }
    }
    cout << stat[idx] << ' ';
    prod *= prob;
  }
  printf("%.2f", (prod*0.65 -1)*2);
  return 0;
}
