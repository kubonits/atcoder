#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 998244353
using namespace std;
typedef long long ll;
int main() {
  int n, cnt, sum = 0, mini;
  vector<pair<int, int> > vp, vm;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    cnt = 0;
    mini = 0;
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == '(') {
        cnt++;
      } else {
        cnt--;
      }
      mini = min(mini, cnt);
    }
    sum += cnt;
    if (cnt > 0) {
      vp.push_back({mini, cnt});
    } else {
      vm.push_back({mini - cnt, cnt});
    }
  }
  sort(vm.begin(), vm.end());
  sort(vp.begin(), vp.end());
  if (sum != 0) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < vp.size(); i++) {
    if (sum + vp[vp.size() - 1 - i].first < 0) {
      cout << "No" << endl;
      return 0;
    }
    sum += vp[vp.size() - 1 - i].second;
  }
  for (int i = 0; i < vm.size(); i++) {
    if (sum + vm[i].first + vm[i].second < 0) {
      cout << "No" << endl;
      return 0;
    }
    sum += vm[i].second;
  }
  cout << "Yes" << endl;
}