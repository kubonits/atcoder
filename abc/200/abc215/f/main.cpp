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
  int n, left = 0, right = 1000000000, mid, x, y, flag;
  vector<pair<int, int> > v, mini, maxi;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back({x, y});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    mini.push_back({v[i].second, v[i].second});
    maxi.push_back({v[i].second, v[i].second});
  }
  v.push_back(v.back());
  for (int i = 1; i < n; i++) {
    mini[i].first = min(mini[i].first, mini[i - 1].first);
    maxi[i].first = max(maxi[i].first, maxi[i - 1].first);
  }
  for (int i = n - 2; i >= 0; i--) {
    mini[i].second = min(mini[i].second, mini[i + 1].second);
    maxi[i].second = max(maxi[i].second, maxi[i + 1].second);
  }
  mini.push_back(mini.back());
  maxi.push_back(maxi.back());
  while (left <= right) {
    mid = (left + right) / 2;
    flag = 0;
    int p = 1;
    for (int i = 0; i < n; i++) {
      while (p < n && v[p].first - v[i].first < mid) {
        p++;
      }
      if ((maxi[p].second - v[i].second >= mid ||
           v[i].second - mini[p].second >= mid) &&
          v[p].first - v[i].first >= mid) {
        flag = 1;
      }
    }
    p = n - 1;
    for (int i = n - 1; i >= 0; i--) {
      while (p > 0 && v[i].first - v[p].first < mid) {
        p--;
      }
      if ((maxi[p].first - v[i].second >= mid ||
           v[i].second - mini[p].first >= mid) &&
          v[i].first - v[p].first >= mid) {
        flag = 1;
      }
    }
    if (flag) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << right << endl;
}