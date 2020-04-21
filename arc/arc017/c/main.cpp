#include <iostream>
#include <map>
using namespace std;

int n, x, w[32], ans;
map<int, int> m;

void dfs(int i, int sum) {
  if (i == n / 2) {
    if (m.find(sum) == m.end()) {
      m.insert({sum, 1});
    } else {
      m[sum]++;
    }
    return;
  }
  dfs(i + 1, sum + w[i]);
  dfs(i + 1, sum);
  return;
}

void dfs2(int i, int sum) {
  if (i == n) {
    if (m.find(x - sum) != m.end()) {
      ans += m[x - sum];
    }
    return;
  }
  dfs2(i + 1, sum + w[i]);
  dfs2(i + 1, sum);
  return;
}

int main() {
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  if (n == 1) {
    cout << (x == w[0]) << endl;
    return 0;
  }
  dfs(0, 0);
  dfs2(n / 2, 0);
  cout << ans << endl;
}