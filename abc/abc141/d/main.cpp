#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
int main() {
  int n, m;
  ll a, ans = 0LL;
  priority_queue<ll> q;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a;
    q.push(a);
    ans += a;
  }
  for (int i = 0; i < m; i++) {
    a = q.top();
    q.pop();
    ans -= a;
    a /= 2LL;
    ans += a;
    q.push(a);
  }
  cout << ans << endl;
}