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
  int h, w, k, cnt, ans = 0;
  cin >> h >> w >> k;
  string s[6];
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < (1 << (h + w)); i++) {
    cnt = 0;
    for (int j = 0; j < h; j++) {
      for (int k = 0; k < w; k++) {
        if (!(i & (1 << k)) && !(i & (1 << (w + j))) && s[j][k] == '#') {
          cnt++;
        }
      }
    }
    if (cnt == k) {
      ans++;
    }
  }
  cout << ans << endl;
}