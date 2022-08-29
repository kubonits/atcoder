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
  int n, a, cnt = 0;
  deque<int> d;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    d.push_back(a);
  }
  while (!d.empty()) {
    if ((d.back() + cnt) % 2 == 0) {
      d.pop_back();
    } else if ((d.front() + cnt) % 2 == 0) {
      d.pop_front();
      cnt++;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
