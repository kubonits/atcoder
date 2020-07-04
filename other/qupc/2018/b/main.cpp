#include <algorithm>
#include <cmath>
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

int main() {
  int n;
  ll a, b, c, sum;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    sum = 100 * a + 10 * b + c;
    if (sum % 2LL == 1LL) {
      cout << "No" << endl;
    } else {
      sum /= 2LL;
      sum -= min(a, sum / 100) * 100;
      sum -= min(b, sum / 10) * 10;
      sum -= min(c, sum);
      if (sum) {
        cout << "No" << endl;
      } else {
        cout << "Yes" << endl;
      }
    }
  }
}