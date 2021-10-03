#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
#include <cstring>
int n, p, q, x, y;
int cnt;
vector<vector<int> > v, u;
vector<int> in, out, depth;

void dfs(int x, int y) {
  depth[x] = y;
  in[x] = cnt;
  u[y].push_back(cnt++);
  for (int i = 0; i < v[x].size(); i++) {
    dfs(v[x][i], y + 1);
  }
  out[x] = cnt++;
}

int query(int x, int y) {
  if (y >= n || u[y].empty()) {
    return 0;
  }
  int left = 0, right = u[y].size() - 1, mid;

  while (left <= right) {
    mid = (left + right) / 2;
    if (u[y][mid] >= x) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return right;
}

int main() {
  cin >> n;
  v.resize(n);
  u.resize(n);
  in.resize(n);
  out.resize(n);
  depth.resize(n);
  for (int i = 1; i < n; i++) {
    cin >> p;
    p--;
    v[p].push_back(i);
  }
  dfs(0, 0);
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> x >> y;
    x--;
    cout << query(out[x], y) - query(in[x], y) << endl;
  }
}