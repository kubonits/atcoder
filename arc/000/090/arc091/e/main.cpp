//解説AC
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  if (a + b > n + 1LL || a * b < n) {
    cout << -1 << endl;
    return 0;
  }
  if (a >= b) {
    for (int i = 0; i < a; i++) {
      cout << n - a + i + 1 << " ";
    }
    n -= a;
    if (b <= 2) {
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
    } else {
      b--;
      for (int i = 0; i < n % b; i++) {
        for (int j = 0; j < n / b + 1; j++) {
          cout << n - (i + 1) * (n / b + 1) + j + 1 << " ";
        }
      }
      int nn = n - (n % b) * (n / b + 1);
      b -= n % b;
      if (b) {
        n = nn;
        a = n / b;
        for (int i = 0; i < n; i++) {
          cout << n - (i / a + 1) * a + i % a + 1 << " ";
        }
      }
    }
  } else {
    int N = n;
    a ^= b;
    b ^= a;
    a ^= b;
    for (int i = 0; i < a; i++) {
      cout << N + 1 - (n - a + i + 1) << " ";
    }
    n -= a;
    if (b <= 2) {
      for (int i = 1; i <= n; i++) {
        cout << N + 1 - i << " ";
      }
    } else {
      b--;
      for (int i = 0; i < n % b; i++) {
        for (int j = 0; j < n / b + 1; j++) {
          cout << N + 1 - (n - (i + 1) * (n / b + 1) + j + 1) << " ";
        }
      }
      int nn = n - (n % b) * (n / b + 1);
      b -= n % b;
      if (b) {
        n = nn;
        a = n / b;
        for (int i = 0; i < n; i++) {
          cout << N + 1 - (n - (i / a + 1) * a + i % a + 1) << " ";
        }
      }
    }
  }
  cout << endl;
}