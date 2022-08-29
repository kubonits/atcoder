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
  int n;
  set<pair<int, int> > s;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (x[i] == x[j]) {
        s.insert({0, 1});
        s.insert({0, -1});
      } else if (y[i] == y[j]) {
        s.insert({1, 0});
        s.insert({-1, 0});
      } else {
        int g = gcd(abs(x[i] - x[j]), abs(y[i] - y[j]));
        s.insert({(x[i] - x[j]) / g, (y[i] - y[j]) / g});
        s.insert({(x[j] - x[i]) / g, (y[j] - y[i]) / g});
      }
    }
  }
  cout << s.size() << endl;
}
