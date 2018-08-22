#include <iostream>
#include <string>
using namespace std;
int main() {
  int n;
  string lut[] = {
    "tret" , "jan"  , "feb" , 
    "mar"  , "apr"  , "may" , 
    "jun"  , "july" , "aug" , 
    "sep"  , "oct"  , "nov" , 
    "dec"  , "tam"  , "hel" , 
    "maa"  , "huh"  , "tou" , 
    "kes"  , "hei"  , "elo" , 
    "syy"  , "lok"  , "mer" , 
    "jou"  , 
  };
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++ i) {
    string num;
    getline(cin, num);
    if (isdigit(num[0])) {
      // is on earth
      int earth_num = stoi(num), m = 0, n = 0;
      m = earth_num / 13;
      n = earth_num % 13;
      if (m != 0)
        printf("%s ", lut[12+m].c_str());
      if (n != 0)
        printf("%s\n", lut[n].c_str());
    } else {
      string m = "", n = "";
      int f = 0, i_m = 0, i_n = 0;
      for (int j = 0; j < num.length(); ++ j) {
        if (f == 0 && num[j] != ' ')
          m.push_back(num[j]);
        else if (num[j] == ' ')
          f = 1;
        else
          n.push_back(num[j]);
      }
      for (int j = 0; j < 25; ++ j) {
        if (lut[j] == m)
          i_m = j;
        if (lut[j] == n)
          i_n = j;
      }
      if (i_m >= 13)
        i_m = 13 * (i_m - 12);
      if (i_n >= 13)
        i_n = 13 * (i_n - 12);
      printf("%d\n", i_m + i_n);
    }
  }
  return 0;
}
