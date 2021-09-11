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
  int n, a = -1, b = -1, c = -1, d = -1;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    if (v[i] > a) {
      b = a;
      a = v[i];
      d = c;
      c = i;
    } else if (v[i] > b) {
      b = v[i];
      d = i;
    }
  }
  cout << d + 1;
}