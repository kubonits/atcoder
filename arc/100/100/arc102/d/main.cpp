#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int l, sum = 0, p, a[20] = {};
  vector<pair<pair<int, int>, int> > e;
  cin >> l;
  for (int i = 0; i < 19; i++) {
    e.push_back({{i + 1, i + 2}, 0});
  }
  p = 0;
  a[0] = 0;
  for (int i = 0; i < 19; i++) {
    if (sum + (1 << i) < l) {
      e.push_back({{19 - i, 20 - i}, (1 << i)});
      sum += (1 << i);
    }
    a[i + 1] = a[i] + (1 << i);
  }
  for (int i = 18; i >= 0; i--) {
    if (sum + 1 + a[i] < l) {
      e.push_back({{1, 20 - i}, sum + 1});
      sum += (1 << i);
    }
  }
  cout << 20 << " " << e.size() << endl;
  for (int i = 0; i < e.size(); i++) {
    cout << e[i].first.first << " " << e[i].first.second << " " << e[i].second
         << endl;
  }
}