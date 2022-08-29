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

int main() {
  int n, a, b;
  cin >> n;
  vector<int> v(n + 1);
  set<int> s;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    v[a]++;
    v[b]++;
    if (v[a] == 2) {
      s.insert(a);
    }
    if (v[b] == 2) {
      s.insert(b);
    }
    if (s.size() > 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
