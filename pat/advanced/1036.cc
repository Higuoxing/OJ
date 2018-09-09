#include <iostream>
#include <cmath>
using namespace std;

int main() {
  string name, number, fname,
         mname, fnumber, mnumber;
  int n, mark, low = 999999, high = -1;
  char sex;
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    cin >> name >> sex >> number >> mark;
    if (sex == 'M') {
      if (mark < low) {
        low = mark;
        mname = name;
        mnumber = number;
      }
    } else if (sex == 'F') {
      if (mark > high) {
        high = mark;
        fname = name;
        fnumber = number;
      }
    }
  }

  if (high != -1) printf("%s %s\n", fname.c_str(), fnumber.c_str());
  else printf("Absent\n");
  if (low != 999999) printf("%s %s\n", mname.c_str(), mnumber.c_str());
  else printf("Absent\n");
  if (low != 999999 && high != -1) printf("%d", abs(high - low));
  else printf("NA");
  return 0;
}
