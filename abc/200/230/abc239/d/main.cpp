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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  set<int> s;
  for (int i = 2; i <= 200; i++) {
    int flag = 1;
    for (int j = 2; j < i; j++) {
      if (i % j == 0) {
        flag = 0;
      }
    }
    if (flag) {
      s.insert(i);
    }
  }
  for (int i = a; i <= b; i++) {
    int flag = 1;
    for (int j = c; j <= d; j++) {
      if (s.find(i + j) != s.end()) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      cout << "Takahashi" << endl;
      return 0;
    }
  }
  cout << "Aoki" << endl;
}
