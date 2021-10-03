#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
ll h[200000], ans;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  sort(h, h + n);
  for (int i = 0; i < n - k; i++) {
    ans += h[i];
  }
  cout << ans << endl;
}