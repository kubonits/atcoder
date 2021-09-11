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
  ll k, a, b;
  cin >> n >> k;
  vector<pair<ll, ll> > v;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    if (k < v[i].first) {
      cout << k << endl;
      return 0;
    } else {
      k += v[i].second;
    }
  }
  cout << k << endl;
}