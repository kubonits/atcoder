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
  int n, ans = 100;
  for (int i = 0; i < 4; i++) {
    cin >> n;
    ans = min(ans, n);
  }
  cout << ans << endl;
}
