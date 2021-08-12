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
  int h, w, ans = 0;
  string s[100];
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w - 1; j++) {
      if (s[i][j] == '.' && s[i][j + 1] == '.') {
        ans++;
      }
    }
  }
  for (int i = 0; i < h - 1; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '.' && s[i + 1][j] == '.') {
        ans++;
      }
    }
  }
  cout << ans << endl;
}