#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int n, a;
  vector<int> v;
  vector<pair<int, int> > p;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  for (int i = 1; i < n - 1; i++) {
    if (v[i] > 0) {
      p.push_back({v[0], v[i]});
      v[0] -= v[i];
    } else {
      p.push_back({v[n - 1], v[i]});
      v[n - 1] -= v[i];
    }
  }
  p.push_back({v[n - 1], v[0]});
  v[n - 1] -= v[0];
  cout << v[n - 1] << endl;
  for (int i = 0; i < n - 1; i++) {
    cout << p[i].first << " " << p[i].second << endl;
  }
}