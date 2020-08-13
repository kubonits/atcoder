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

int main() {
  ll n, a, x, de[26], ans;
  char c;
  deque<pair<int, ll> > d;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a == 1) {
      cin >> c >> x;
      d.push_back({c - 'a', x});
    } else {
      cin >> x;
      ans = 0LL;
      for (int i = 0; i < 26; i++) {
        de[i] = 0LL;
      }
      while (x && !d.empty()) {
        if (d.front().second <= x) {
          de[d.front().first] += d.front().second;
          x -= d.front().second;
          d.pop_front();
        } else {
          de[d.front().first] += x;
          d.front().second -= x;
          x = 0LL;
        }
      }
      for (int i = 0; i < 26; i++) {
        ans += de[i] * de[i];
      }
      cout << ans << endl;
    }
  }
}