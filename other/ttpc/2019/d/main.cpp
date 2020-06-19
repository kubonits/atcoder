#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
  int n, ans = 0, cnt;
  set<int> p, c;
  cin >> n;
  vector<int> a(n), sieve(1000001);
  for (int i = 2; i <= 1000000; i++) {
    sieve[i] = 1;
  }
  for (int i = 2; i * i <= 1000000; i++) {
    if (sieve[i]) {
      for (int j = i * i; j <= 1000000; j += i) {
        sieve[j] = 0;
      }
    }
  }
  for (int i = 2; i <= 1000000; i++) {
    if (sieve[i]) {
      p.insert(i);
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (sieve[a[i]]) {
      cnt = 1;
      while (sieve[a[i] - 2]) {
        cnt++;
        a[i] -= 2;
      }
      a[i] = cnt;
    } else if (a[i] == 1) {
      a[i] = 0;
    } else if (a[i] % 2 == 0 || sieve[a[i] - 2]) {
      a[i] = 2;
    } else {
      a[i] = 0;
    }
    ans ^= a[i];
  }
  if (ans) {
    cout << "An" << endl;
  } else {
    cout << "Ai" << endl;
  }
}