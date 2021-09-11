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
  int s, t, ans = 0;
  cin >> s >> t;
  for (int i = 0; i <= s; i++) {
    for (int j = 0; i + j <= s; j++) {
      for (int k = 0; i + j + k <= s; k++) {
        if (i * j * k <= t) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}