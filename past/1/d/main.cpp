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
  int n, y, a;
  set<int> s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (s.find(a) == s.end()) {
      s.insert(a);
    } else {
      y = a;
    }
  }
  if (s.size() == n) {
    cout << "Correct" << endl;
  } else {
    for (int i = 1; i <= n; i++) {
      if (s.find(i) == s.end()) {
        cout << y << " " << i << endl;
      }
    }
  }
}