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
  int n, ans = 0, x;
  cin >> n;
  vector<int> a(n), b(200010);
  for (int i = 0; i < n; i++) {
    cin >> x;
    b[x] = 1;
    while (b[ans] == 1) {
      ans++;
    }
    cout << ans << endl;
  }
}