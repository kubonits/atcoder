#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, a[100000], r[100000], ans;
vector<int> v[100001];
int main() {
  cin >> n;
  ans = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v[a[i]].push_back(i);
  }
  for (int i = 1; i <= 100000; i++) {
    v[i].push_back(n);
    for (int j = 0; j < v[i].size() - 1; j++) {
      r[v[i][j]] = v[i][j + 1];
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    r[i] = min(r[i], r[i + 1]);
    ans = max(ans, r[i] - i);
  }
  cout << ans << endl;
}