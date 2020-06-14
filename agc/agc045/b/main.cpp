#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  int n, z = 0, ans = 100000000, fz = -1000000;
  string s;
  vector<int> sum, maxi;
  cin >> s;
  n = s.size();
  sum.resize(s.size() + 10);
  maxi.resize(sum.size());
  sum[0] = 0;
  for (int i = 0; i < s.size(); i++) {
    sum[i + 1] = sum[i];
    if (s[i] == '1') {
      sum[i + 1]++;
    } else {
      sum[i + 1]--;
    }
    z = max(z, sum[i + 1]);
  }
  maxi[n] = z;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '1') {
      maxi[i] = maxi[i + 1] - 1;
    } else {
      maxi[i] = min(z, maxi[i + 1] + 1);
    }
  }
  int cnt = 0;
  int mini = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1' || s[i] == '?' && maxi[i + 1] >= cnt + 1) {
      cnt++;
    } else {
      cnt--;
    }
    mini = min(mini, cnt);
  }
  ans = z - mini;
  z++;
  maxi[n] = z;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '1') {
      maxi[i] = maxi[i + 1] - 1;
    } else {
      maxi[i] = min(z, maxi[i + 1] + 1);
    }
  }
  cnt = 0;
  mini = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1' || s[i] == '?' && maxi[i + 1] >= cnt + 1) {
      cnt++;
    } else {
      cnt--;
    }
    mini = min(mini, cnt);
  }
  ans = min(ans, z - mini);
  cout << ans << endl;
}