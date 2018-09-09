#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int n, arr[1010];
  fill(arr, arr+1010, -1);
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i)
    scanf("%d", &arr[i]);
  return 0;
}
