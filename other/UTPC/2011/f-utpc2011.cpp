#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>
#include <vector>
using namespace std;

vector<vector<pair<int, int> > > tree;

int main() {
  int n, k;
  set<int> s;
  set<pair<int, int> > p;
  scanf("%d%d", &n, &k);
  tree.resize(k);
  if (n / 2 < k) {
    printf("-1\n");
    return 0;
  }
  for (int a = 2; a <= 2 * k; a++) {
    if (a == 2) {
      tree[0].push_back({1, 2});
    } else if (a % 2) {
      for (int i = 0; i < a / 2; i++) {
        tree[i].push_back({a, i + 1});
      }
    } else {
      for (int i = 1; i <= a / 2; i++) {
        tree[a / 2 - 1].push_back({a, i});
      }
      for (int i = k; i < a - 1; i++) {
        tree[a / 2 - 1].push_back({a - 1, i});
      }
      for (int i = 0; i < a / 2 - 1; i++) {
        tree[i].push_back({a, a / 2 + i + 1});
      }
    }
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < tree.size(); j++) {
      printf("%d %d\n", tree[i][j].first, tree[i][j].second);
    }
    printf("\n");
  }
}