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
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = a; i <= b; i++) {
    if (i % c == 0) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
