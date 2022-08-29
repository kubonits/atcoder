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
  ll n, ans, sum = 0, a, b;
  priority_queue<ll> q;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    sum += a;
    q.push(2 * a + b);
  }
  ans = 0;
  while (!q.empty() && sum >= 0) {
    sum -= q.top();
    q.pop();
    ans++;
  }
  cout << ans << endl;
}
