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

int main() {
  int n;
  cin >> n;
  set<int> s;
  vector<vector<int> > va(n + 1), vb(n + 1);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    va[a[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    vb[b[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    s.insert(i);
  }
  for (int i = 1; i <= n; i++) {
    if (!va[i].empty() && !vb[i].empty()) {
      for (int j = vb[i][0] - va[i].back(); j <= vb[i].back() - va[i][0]; j++) {
        s.erase((j + 2 * n) % n);
      }
    }
  }
  if (s.empty()) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    int x = *s.begin();
    for (int i = 0; i < n; i++) {
      cout << b[(i + x + n) % n] << " ";
    }
    cout << endl;
  }
}