#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll r, b, x, y, left, right, mid;
  cin >> r >> b >> x >> y;
  left = 0;
  right = 1000000000000000000;
  while (left <= right) {
    mid = (left + right) / 2L;
    ll rr = r - mid;
    ll bb = b - mid;
    if (rr >= 0LL && bb >= 0LL && rr / (x - 1LL) + bb / (y - 1LL) >= mid) {
      left = mid + 1LL;
    } else {
      right = mid - 1LL;
    }
  }
  cout << right << endl;
}