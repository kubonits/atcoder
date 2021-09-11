#include <deque>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  int n, k;
  ll sum = 0LL, ans = 0LL, a;
  deque<ll> d;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a;
    sum += a;
    d.push_back(a);
    if (i >= k - 1) {
      ans += sum;
      sum -= d.front();
      d.pop_front();
    }
  }
  cout << ans << endl;
}