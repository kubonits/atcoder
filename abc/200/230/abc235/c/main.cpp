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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int n, q, x, k;
  cin >> n >> q;
  vector<int> v(n);
  map<int, vector<int> > mv;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    mv[v[i]].push_back(i + 1);
  }
  for (int i = 0; i < q; i++) {
    cin >> x >> k;
    if (mv.find(x) != mv.end() && mv[x].size() >= k) {
      cout << mv[x][k - 1] << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
