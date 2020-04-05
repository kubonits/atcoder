#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
  int n, x;
  vector<int> r, b;
  char c[10];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%s", &x, c);
    if (c[0] == 'R') {
      r.push_back(x);
    } else {
      b.push_back(x);
    }
  }
  sort(r.begin(), r.end());
  sort(b.begin(), b.end());
  for (int i = 0; i < r.size(); i++) {
    printf("%d\n", r[i]);
  }
  for (int i = 0; i < b.size(); i++) {
    printf("%d\n", b[i]);
  }
}