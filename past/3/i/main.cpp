#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
ll x[100001], y[100001];
int main() {
  ll n, q, a, b, c, flag = 0, temp;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    x[i] = y[i] = i;
  }
  for (int i = 0; i < q; i++) {
    cin >> c;
    if (c == 1) {
      cin >> a >> b;
      if (flag) {
        temp = y[a];
        y[a] = y[b];
        y[b] = temp;
      } else {
        temp = x[a];
        x[a] = x[b];
        x[b] = temp;
      }
    }
    if (c == 2) {
      cin >> a >> b;
      if (flag) {
        temp = x[a];
        x[a] = x[b];
        x[b] = temp;
      } else {
        temp = y[a];
        y[a] = y[b];
        y[b] = temp;
      }
    }
    if (c == 3) {
      flag ^= 1;
    }
    if (c == 4) {
      cin >> a >> b;
      if (flag) {
        temp = a;
        a = b;
        b = temp;
      }
      cout << n * (x[a] - 1) + y[b] - 1LL << endl;
    }
  }
}