#include <iostream>
using namespace std;
int main() {
  int n, cnt = 0;
  double sum = 0.0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    char s0[50], s1[50];
    int flag = 0;
    double num;
    scanf("%s", s0);
    sscanf(s0, "%lf", &num);
    sprintf(s1, "%.2lf", num);
    for (int j = 0; j < strlen(s0); ++ j)
      if (s0[j] != s1[j])
        flag = 1;
    if (flag || num > 1000 || num < -1000)
      printf("ERROR: %s is not a legal number\n", s0);
    else {
      sum += num;
      ++ cnt;
    }
  }
  if (cnt == 0)
    printf("The average of 0 numbers is Undefined");
  else if (cnt == 1)
    printf("The average of 1 number is %.2lf", sum / cnt);
  else
    printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
  return 0;
}
