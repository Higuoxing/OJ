#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> inorder, postorder;
vector<int> level(10000, -1);

void pre(int root, int start, int end, int lev) {
  ++ lev;
  if (start > end) return;
  int i = start;
  while (inorder[i] != postorder[root] && i < end) ++ i;
  level[lev] = postorder[root];
  pre(root - end + i - 1, start, i - 1, 2 * lev + 1);
  pre(root - 1, i + 1, end, 2 * lev + 2);
}

int main() {
  int n;
  scanf("%d", &n);
  inorder.resize(n);
  postorder.resize(n);
  for (int i = 0; i < postorder.size(); ++ i)
    scanf("%d", &postorder[i]);
  for (int i = 0; i < inorder.size(); ++ i)
    scanf("%d", &inorder[i]);
  pre(n-1, 0, n-1, 0);
  
  int cnt = 0;
  for (int i = 0; i < level.size(); ++ i) {
    if (level[i] != -1) {
      ++ cnt;
      printf("%d", level[i]);
      if (cnt != n)
        printf(" ");
    }
  }

  return 0;
}
