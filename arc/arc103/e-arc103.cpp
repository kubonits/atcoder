#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
vector<pair<int, int> > e;
int n, a[100001] = {};
string s;

void dfs(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > n) {
    return;
  }
  if (y == 1) {
    return;
  }
  int maxi = 1;
  int cnt = 0;
  for (int i = 1; i <= y; i++) {
    if (a[i]) {
      cnt++;
    }
  }
  if (cnt)
    for (int i = 1; i <= y / 2; i++) {
      if (a[i] == 1) {
        maxi = i;
      }
    }
  e.push_back({x, x + y - 1});
  dfs(x, maxi);
  dfs(x + maxi, y - maxi);
}

int main() {
  int cnt = 0;
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      a[i + 1] = 1;
      cnt++;
    }
  }
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 2 - i]) {
      printf("-1\n");
      return 0;
    }
  }
  if (s[n - 1] == '1' || s[0] == '0') {
    printf("-1\n");
    return 0;
  }
  if (cnt == n - 1) {
    for (int i = 1; i < n; i++) {
      printf("%d %d\n", i, i + 1);
    }
    return 0;
  }
  if (cnt == 2) {
    for (int i = 2; i <= n; i++) {
      printf("1 %d\n", i);
    }
    return 0;
  }
  dfs(1, s.length());
  for (int i = 0; i < e.size(); i++) {
    printf("%d %d\n", e[i].first, e[i].second);
  }
}