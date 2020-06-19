#include <iostream>
#include <vector>
using namespace std;
int calc(int x) {
  int res = -1;
  for (int i = 30; i >= 0; i--) {
    if (x & (1 << i)) {
      return i;
    }
  }
  return -1;
}

int main() {
  int n, x, y, cnt = 0;
  cin >> n >> x;
  y = x;
  vector<int> a(n + 10);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] != -1) {
      y ^= a[i];
    } else {
      cnt++;
    }
  }
  if (y == 0) {
    for (int i = 0; i < n; i++) {
      if (a[i] != -1) {
        cout << a[i] << " ";
      } else {
        cout << 0 << " ";
      }
    }
    cout << endl;
  } else if (y <= x && cnt) {
    cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == -1 && cnt == 0) {
        cout << y << " ";
        cnt++;
      } else if (a[i] != -1) {
        cout << a[i] << " ";
      } else {
        cout << 0 << " ";
      }
    }
    cout << endl;
  } else if (cnt >= 2 && calc(x) == calc(y)) {
    cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == -1 && cnt == 0) {
        cout << (1 << calc(x)) << " ";
        cnt++;
      } else if (a[i] == -1 && cnt == 1) {
        cnt++;
        cout << (y ^ (1 << calc(x))) << " ";
      } else if (a[i] == -1) {
        cout << 0 << " ";
      } else {
        cout << a[i] << " ";
      }
    }
    cout << endl;
  } else {
    cout << -1 << endl;
  }
}