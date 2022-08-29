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
  ll ans = -1000000000000000000, sum = 0LL;
  priority_queue<ll> q;
  priority_queue<ll, vector<ll>, greater<ll> > q2;
  cin >> n >> k;
  vector<int> t(n + 1);
  vector<ll> y(n + 1);
  t[0] = 1;
  y[0] = 0LL;
  for (int i = 0; i < n; i++) {
    cin >> t[i + 1] >> y[i + 1];
    if (t[i + 1] == 1) {
      sum = y[i + 1];
    } else {
      sum += y[i + 1];
    }
  }
  ans = sum;
  sum = 0LL;
  for (int i = n; i >= 0 && k >= 0; i--) {
    if (t[i] == 2 && y[i] >= 0LL) {
      sum += y[i];
      q2.push(y[i]);
    } else if (t[i] == 2) {
      q.push(y[i]);
    } else {
      while (!q.empty() && q.size() > k) {
        sum += q.top();
        q2.push(q.top());
        q.pop();
      }
      while (!q.empty() && !q2.empty() && q.top() > q2.top()) {
        q.push(q2.top());
        sum -= q2.top();
        q2.pop();
      }
      while (!q.empty() && q.size() > k) {
        sum += q.top();
        q2.push(q.top());
        q.pop();
      }
      k--;
      ans = max(ans, y[i] + sum);
    }
  }
  cout << ans << endl;
}
