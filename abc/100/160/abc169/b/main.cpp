#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
ll a[100000];
int main() {
  int n;
  ll b = 1LL;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0LL) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (1000000000000000000 / b < a[i]) {
      cout << -1 << endl;
      return 0;
    }
    b *= a[i];
    if (b > 1000000000000000000) {
      cout << -1 << endl;
    }
  }
  cout << b << endl;
}