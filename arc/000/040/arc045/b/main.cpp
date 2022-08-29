#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;
int sum[300010];
int main() {
  int n, m, a, b;
  vector<int> v;
  vector<pair<int, int> > p;
  cin >> n >> m;
  set<int> s;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    p.push_back({a, b});
    sum[a]++;
    sum[b + 1]--;
  }
  for (int i = 1; i <= 300000; i++) {
    sum[i] += sum[i - 1];
    if (sum[i] == 1) {
      s.insert(i);
    }
  }
  for (int i = 0; i < m; i++) {
    set<int>::iterator it = s.lower_bound(p[i].first);
    if (it == s.end() || *it > p[i].second) {
      v.push_back(i + 1);
    }
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
}