#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n;
  string s[1002];
  pair<int, int> p[1002];
  queue<int> q;
  cin >> s[0] >> s[1];
  if (s[0] == s[1]) {
    cout << 0 << endl;
    cout << s[0] << endl;
    cout << s[0] << endl;
    return 0;
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i + 2];
  }
  for (int i = 0; i < n + 2; i++) {
    p[i] = {10000, -1};
  }
  q.push(0);
  p[0].first = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 1; i < n + 2; i++) {
      int cnt = 0;
      for (int j = 0; j < s[i].length(); j++) {
        if (s[x][j] != s[i][j]) {
          cnt++;
        }
      }
      if (cnt <= 1 && p[i].first > p[x].first + 1) {
        p[i].first = p[x].first + 1;
        p[i].second = x;
        q.push(i);
      }
    }
  }
  if (p[1].first == 10000) {
    cout << -1 << endl;
  } else {
    vector<string> ans;
    int x = 1;
    while (x != 0) {
      ans.push_back(s[x]);
      x = p[x].second;
    }
    cout << ans.size() - 1 << endl;
    reverse(ans.begin(), ans.end());
    cout << s[0] << endl;
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << endl;
    }
  }
}