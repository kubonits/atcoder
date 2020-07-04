#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  int n, k;
  ll sum = 0LL;
  cin >> n >> k;
  if (n * 2 - 1 == k) {
    for (int i = 1; i <= k; i++) {
      cout << i << " ";
    }
    cout << endl;
    cout << "YES" << endl;
    for (int i = 1; i <= k; i++) {
      if (i == k) {
        cout << n << " ";
      } else {
        cout << min(k - i, i) << " ";
      }
    }
    cout << endl;
  } else if (2 * n == k) {
    for (int i = 1; i <= k; i++) {
      cout << i << " ";
    }
    cout << endl;
    cout << "YES" << endl;
    for (int i = 1; i <= k; i++) {
      cout << min(i, k - i + 1) << " ";
    }
    cout << endl;
  } else {
    for (int i = 0; i < k; i++) {
      if (i < k - 2 * n + 2) {
        cout << 1000 + i << " ";
        sum += 1000 + i;
      } else if (sum % 2 == 1) {
        if (i < k - n + 1) {
          cout << sum / 2 - (k - n + 1 - i) + 1 << " ";
        } else {
          cout << sum / 2 - (k - n + 1 - i) + 1 << " ";
        }
      } else if (i < k - n + 1) {
        cout << sum / 2 - (k - n + 1 - i) << " ";
      } else {
        cout << sum / 2 - (k - n + 1 - i) + 1 << " ";
      }
    }
    cout << endl;
    cout << "YES" << endl;
    for (int i = 0; i < k; i++) {
      if (i < k - 2 * n + 2) {
        cout << 1 << " ";
      } else {
        cout << min(i - (k - 2 * n), k - i + 1) << " ";
      }
    }
  }
}