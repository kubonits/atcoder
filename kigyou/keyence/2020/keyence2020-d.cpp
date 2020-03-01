#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<int> odd, even;
int n, a[18], b[18];
int dfs(int x) {
  int res = 1000000000;
  if (x == n) {
    vector<pair<int, int> > oddp, evenp;
    for (int i = 0; i < odd.size(); i++) {
      if (odd[i] % 2) {
        oddp.push_back({b[odd[i]], odd[i]});
      } else {
        oddp.push_back({a[odd[i]], odd[i]});
      }
    }
    for (int i = 0; i < even.size(); i++) {
      if (even[i] % 2 == 0) {
        evenp.push_back({b[even[i]], even[i]});
      } else {
        evenp.push_back({a[even[i]], even[i]});
      }
    }
    sort(oddp.begin(), oddp.end());
    sort(evenp.begin(), evenp.end());

    for (int i = 0; i < oddp.size(); i++) {
      if (n % 2 == 0 || i != oddp.size() - 1) {
        if (oddp[i].first > evenp[i].first) {
          return res;
        }
      }
      if (i != 0) {
        if (oddp[i].first < evenp[i - 1].first) {
          return res;
        }
      }
    }
    res = 0;
    for (int i = 0; i < oddp.size(); i++) {
      for (int j = i + 1; j < oddp.size(); j++) {
        if (oddp[i].second > oddp[j].second) {
          res++;
        }
      }
      for (int j = i; j < even.size(); j++) {
        if (oddp[i].second > evenp[j].second) {
          res++;
        }
      }
    }
    for (int i = 0; i < evenp.size(); i++) {
      for (int j = i + 1; j < oddp.size(); j++) {
        if (evenp[i].second > oddp[j].second) {
          res++;
        }
      }
      for (int j = i + 1; j < evenp.size(); j++) {
        if (evenp[i].second > evenp[j].second) {
          res++;
        }
      }
    }
    return res;
  }
  if (odd.size() < (n + 1) / 2) {
    odd.push_back(x);
    res = min(res, dfs(x + 1));
    odd.pop_back();
  }
  if (even.size() < (n) / 2) {
    even.push_back(x);
    res = min(res, dfs(x + 1));
    even.pop_back();
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  int ans = dfs(0);
  if (ans == 1000000000) {
    printf("-1\n");
  } else {
    printf("%d\n", ans);
  }
}