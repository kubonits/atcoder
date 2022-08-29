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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<vector<int> > v(k);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v[i % k].push_back(a[i]);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < k; i++) {
    sort(v[i].begin(), v[i].end());
  }
  for (int i = 0; i < n; i++) {
    if (a[i] != v[i % k][i / k]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
