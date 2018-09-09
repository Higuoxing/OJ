#include <iostream>
using namespace std;
int main() {
  int poly_exp;
  float poly_coeff;
  int poly_term;
  float poly_res[1001] = {0};
  cin >> poly_term;
  for (int i = 0; i < poly_term; ++i) {
    cin >> poly_exp >> poly_coeff;
    poly_res[poly_exp] += poly_coeff;
  }

  cin >> poly_term;
  for (int i = 0; i < poly_term; ++i) {
    cin >> poly_exp >> poly_coeff;
    poly_res[poly_exp] += poly_coeff;
  }

  int cnt = 0;
  for (int i = 0; i < 1001; ++i) {
    if (poly_res[i] != 0.0) ++cnt;
  }

  cout << cnt;

  for (int i = 1000; i > -1; --i) {
    if (poly_res[i] != 0) printf(" %d %.1f", i, poly_res[i]);
  }

  return 0;
}
