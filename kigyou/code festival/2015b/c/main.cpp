#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, p = 0;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0; i < a.size(); i++) {
    if (p < b.size() && a[i] >= b[p]) {
      p++;
    }
  }
  if (p == b.size()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}