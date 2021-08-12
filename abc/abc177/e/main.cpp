#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
#include <cstring>

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int n, x, flag, flag2 = 1;
  cin >> n;
  vector<int> a(n);
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n && flag2 == 1; i++) {
    x = a[i];
    for (int j = 2; j <= 1000 && x != 1; j++) {
      flag = 0;
      while (x % j == 0) {
        x /= j;
        flag = 1;
      }
      if (flag && s.find(j) == s.end()) {
        s.insert(j);
      } else if (flag) {
        flag2 = 0;
        break;
      }
    }
    if (x != 1 && s.find(x) == s.end()) {
      s.insert(x);
    } else if (x != 1) {
      flag2 = 0;
      break;
    }
  }
  if (flag2 == 1) {
    cout << "pairwise coprime" << endl;
    return 0;
  }
  int g = a[0];
  for (int i = 0; i < n; i++) {
    g = gcd(g, a[i]);
  }
  cout << (g == 1 ? "setwise coprime" : "not coprime") << endl;
}