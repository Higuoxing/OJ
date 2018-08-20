#include <iostream>
#include <string>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    string s, a, b;
    cin >> s;
    a = s.substr(0, s.length()/2);
    b = s.substr(s.length()/2, s.length());
    long long int_s, int_a, int_b;
    int_s = stoi(s);
    int_a = stoi(a);
    int_b = stoi(b);
    if (int_a == 0 || int_b == 0)
      printf("No\n");
    else if (int_s % (int_a * int_b) == 0)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
