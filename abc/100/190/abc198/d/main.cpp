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
int cnt;
string s[3], t = "";
set<char> se;

int dfs(int n, vector<int> v) {
  if (n == t.length()) {
    cnt++;
    ll num[3] = {0};
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < s[i].length(); j++) {
        num[i] *= 10;
        for (int k = 0; k < t.length(); k++) {
          if (s[i][j] == t[k]) {
            num[i] += v[k];
            break;
          }
        }
      }
    }
    if (num[0] + num[1] == num[2]) {
      for (int i = 0; i < 3; i++) {
        if (to_string(num[i]).length() != s[i].length() || num[i] == 0) {
          return 0;
        }
      }
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < s[i].length(); j++) {
          for (int k = 0; k < t.length(); k++) {
            if (s[i][j] == t[k]) {
              cout << v[k];
              break;
            }
          }
        }
        cout << endl;
      }
      return 1;
    }
    return 0;
  }
  for (int i = 0; i < 10; i++) {
    int flag = 1;
    for (int j = 0; j < v.size(); j++) {
      if (i == v[j]) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      v.push_back(i);
      if (dfs(n + 1, v)) {
        return 1;
      }
      v.pop_back();
    }
  }
  return 0;
}

int main() {
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
    for (int j = 0; j < s[i].length(); j++) {
      if (se.find(s[i][j]) == se.end()) {
        se.insert(s[i][j]);
        t += s[i].substr(j, 1);
      }
    }
  }
  if (se.size() > 10) {
    cout << "UNSOLVABLE" << endl;
    return 0;
  }
  vector<int> v;
  if (!dfs(0, v)) {
    cout << "UNSOLVABLE" << endl;
  }
}
