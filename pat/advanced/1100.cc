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
    "jou"
  };
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++ i) {
    string num;
    getline(cin, num);
    if (isdigit(num[0])) {
      // this is 10-digit
      int n = stoi(num) / 13,
          m = stoi(num) % 13;
      if (n != 0)
        cout << lut[n+12];
      if (n != 0 && m != 0)
        cout << ' ' << lut[m];
      else if (n == 0)
        cout << lut[m];
    } else {
      // 13-digits
      string m = "", n = "";
      int f = 0;
      for (int j = 0; j < num.length(); ++ j) {
        if (num[j] == ' ')
          f = 1;
        if (f == 0 && num[j] != ' ')
          m.push_back(num[j]);
        if (f == 1 && num[j] != ' ')
          n.push_back(num[j]);
      }
      int i_m = 0, i_n = 0;
      for (int k = 0; k < 25; ++ k) {
        if (lut[k] == m)
          i_m = k;
        if (lut[k] == n)
          i_n = k;
      }
      if (i_m > 12)
        i_m = 13*(i_m - 12);
      cout << i_m + i_n;
    }
    cout << endl;
  }
  return 0;
}
