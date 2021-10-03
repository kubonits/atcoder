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
  ll n, a, ans = 0LL;
  map<ll, ll> m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    m[a]++;
  }
  for (auto x : m) {
    ans += x.second * (n - x.second);
  }
  cout << ans / 2LL << endl;
}