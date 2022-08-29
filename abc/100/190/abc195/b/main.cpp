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
  int a, b, w, mini = 1000000000, maxi = -1;
  cin >> a >> b >> w;
  for (int i = 1; i <= 1000 * w; i++) {
    if (a * i <= 1000 * w && 1000 * w <= b * i) {
      mini = min(mini, i);
      maxi = max(maxi, i);
    }
  }
  if (maxi == -1) {
    cout << "UNSATISFIABLE" << endl;
  } else {
    cout << mini << " " << maxi << endl;
  }
}
