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
  ll n, a;
  vector<ll> v(1000001);
  cin >> a >> n;
  queue<ll> q;
  for (int i = 0; i <= 1000000; i++) {
    v[i] = 1000000000;
  }
  v[1] = 0;
  q.push(1);
  while (!q.empty()) {
    ll x = q.front();
    q.pop();
    if (x * a <= 1000000 && v[x * a] > v[x] + 1) {
      v[a * x] = v[x] + 1;
      q.push(a * x);
    }
    ll y = 100000;
    while (y > 1 && x % 10) {
      if (x >= y) {
        if (v[x / 10 + x % 10 * y] > v[x] + 1) {
          v[x / 10 + x % 10 * y] = v[x] + 1;
          q.push(x / 10 + x % 10 * y);
        }
        y = 0;
      }
      y /= 10;
    }
  }
  cout << (v[n] != 1000000000 ? v[n] : -1) << endl;
}
