#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  ll n, a, b, s, sum = 0LL, mini = 1000000000LL, maxi = 0LL;
  cin >> n >> a >> b;
  double p, q;
  for (int i = 0; i < n; i++) {
    cin >> s;
    sum += s;
    maxi = max(maxi, s);
    mini = min(mini, s);
  }
  if (maxi == mini) {
    if (b != 0) {
      cout << -1 << endl;
      return 0;
    } else {
      cout << 0 << " " << a - s << endl;
    }
  }
  p = double(b) / double(maxi - mini);
  q = (double)a - p * (double)sum / (double)n;
  cout << fixed << setprecision(7) << p << " " << q << endl;
}