#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int n, a[200000], b[200001], visited[200000], c[200001];
ll dis[200000];
vector<int> v[200001];
ll k;
vector<int> ans;
int main() {
  int p = 0;
  ll cnt = 0LL;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v[a[i]].push_back(i);
    b[i] = v[a[i]].size();
  }
  do {
    if (b[p] == v[a[p]].size()) {
      cnt++;
      p = v[a[p]][0];
    } else {
      p = v[a[p]][b[p]];
    }
    p++;
    p %= n;
    if (p == 0) {
      cnt++;
    }
  } while (p != 0);
  if (cnt < k) {
    k %= cnt;
    while (k >= 2) {
      int next = v[a[p]][b[p] % v[a[p]].size()];
      next++;
      next %= n;
      if (b[p] == v[a[p]].size() || next == 0) {
        k--;
      }
      p = next;
    }
    for (int j = p; j < n; j++) {
      if (c[a[j]] == 0) {
        ans.push_back(a[j]);
        c[a[j]]++;
      } else {
        while (c[a[j]]) {
          c[ans.back()]--;
          ans.pop_back();
        }
      }
    }
  } else {
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < n; j++) {
        if (c[a[j]] == 0) {
          ans.push_back(a[j]);
          c[a[j]]++;
        } else {
          while (c[a[j]]) {
            c[ans.back()]--;
            ans.pop_back();
          }
        }
      }
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}