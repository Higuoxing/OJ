#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n) {
  if(n <= 1) return false;
  int Sqrt = sqrt((double) n);
  for(int i = 2; i <= Sqrt; i++) {
    if(n % i == 0)
      return false;
  }
  return true;
}
int main() {
  int n, winner[10001];
  string lut[5] = { "Are you kidding?", "Mystery Award", "Minion", "Chocolate", "Checked" };
  fill(winner, winner+10001, 0);
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    int v;
    scanf("%d", &v);
    if (i == 0)
      // first one
      winner[v] = 1;
    else if (isPrime(i+1))
      winner[v] = 2;
    else 
      winner[v] = 3;
  }

  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    int v;
    scanf("%d", &v);
    printf("%04d: %s\n", v, lut[winner[v]].c_str());
    if (winner[v] != 0)
      winner[v] = 4;
  }
  return 0;
}
