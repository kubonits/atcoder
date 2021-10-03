#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int n, m, a[50], b[50], u[20], v[20];
  vector<int> g[51];
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", &a[i], &b[i]);
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u[i], &v[i]);
  }
}