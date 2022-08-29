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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int n, w;
  cin >> n >> w;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  a.push_back(0);
  a.push_back(0);
  set<int> s;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n + 1; j++) {
      for (int k = j + 1; k < n + 2; k++) {
        if (a[i] + a[j] + a[k] <= w) {
          s.insert(a[i] + a[j] + a[k]);
        }
      }
    }
  }
  cout << s.size() << endl;
}
