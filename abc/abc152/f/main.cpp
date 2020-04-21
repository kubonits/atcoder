#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
int s[(1 << 20)][50];
vector<int> v[51];
int p;
int n, m, a[50], b[50], cnt, cnt2;
ll ans;

int dfs(int x, int y, int z) {
  if (x == z) {
    for (int j = 0; j < n - 1; j++) {
      if (a[j] == x && b[j] == y || a[j] == y && b[j] == x) {
        s[p][j] = 1;
      }
    }
    return 1;
  }
  for (int i = 0; i < v[x].size(); i++) {
    if (v[x][i] != y && dfs(v[x][i], x, z) == 1) {
      for (int j = 0; j < n - 1; j++) {
        if (a[j] == x && b[j] == y || a[j] == y && b[j] == x) {
          s[p][j] = 1;
        }
      }
      return 1;
    }
  }
  return 0;
}

int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i] >> b[i];
    v[a[i]].push_back(b[i]);
    v[b[i]].push_back(a[i]);
  }
  cin >> m;
  ans = (1LL << (n - 1));
  for (int i = 0; i < m; i++) {
    cin >> a[n] >> b[n];
    p = (1 << i);
    dfs(a[n], -1, b[n]);
  }
  for (int i = 1; i < (1 << m); i++) {
    for (int j = m - 1; j >= 0; j--) {
      if ((1 << j) & i) {
        p = j;
        break;
      }
    }
    cnt = 0;
    for (int j = 0; j < n - 1; j++) {
      if (s[(1 << p)][j] || s[i ^ (1 << p)][j]) {
        s[i][j] = 1;
        cnt++;
      }
    }
    cnt2 = 0;
    for (int j = 0; j < m; j++) {
      if (i & (1 << j)) {
        cnt2++;
      }
    }
    if (cnt2 % 2) {
      ans -= (1LL << (n - 1 - cnt));
    } else {
      ans += (1LL << (n - 1 - cnt));
    }
  }
  cout << ans << endl;
}