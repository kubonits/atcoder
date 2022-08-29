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
  double n, ans = 0.0;
  cin >> n;
  for (int i = 0.0; i <= 100.0; i += 1.0) {
    if (abs(ans - n) >= abs(i - n)) {
      ans = i;
    }
  }
  cout << ans << endl;
}
