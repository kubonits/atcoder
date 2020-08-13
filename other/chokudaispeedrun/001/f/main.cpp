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

int main() {
  int n, a, maxi = 0, ans = 1;
  cin >> n;
  cin >> maxi;
  for (int i = 1; i < n; i++) {
    cin >> a;
    if (maxi < a) {
      maxi = a;
      ans++;
    }
  }
  cout << ans << endl;
}