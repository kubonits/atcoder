#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  string a, b, c, d;
  vector<int> v;
  int n, cnt[26] = {}, flag = 0;
  cin >> a >> b;
  n = a.length();
  for (int i = 0; i < n; i++) {
    cnt[a[i] - 'a']++;
    cnt[b[i] - 'a']--;
    if (a[i] != b[i]) {
      v.push_back(i);
    }
  }
  for (int i = 0; i < 26; i++) {
    if (cnt[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  if (v.size() > 6) {
    cout << "NO" << endl;
    return 0;
  }
  if (!v.empty()) {
    for (int i = 0; i < n; i++) {
      cnt[a[i] - 'a']++;
      if (cnt[a[i] - 'a'] >= 2) {
        flag = 1;
      }
    }
    for (int i = 0; i < v.size(); i++) {
      for (int j = i + 1; j < v.size(); j++) {
        for (int k = 0; k < v.size(); k++) {
          for (int x = k + 1; x < v.size(); x++) {
            for (int y = 0; y < v.size(); y++) {
              for (int z = y + 1; z < v.size(); z++) {
                c = a;
                d = a;
                d[0] = c[v[i]];
                c[v[i]] = c[v[j]];
                c[v[j]] = d[0];
                d[0] = c[v[k]];
                c[v[k]] = c[v[x]];
                c[v[x]] = d[0];
                if (flag && b == c) {
                  cout << "YES" << endl;
                  return 0;
                }
                d[0] = c[v[y]];
                c[v[y]] = c[v[z]];
                c[v[z]] = d[0];
                if (b == c) {
                  cout << "YES" << endl;
                  return 0;
                }
              }
            }
          }
        }
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      cnt[a[i] - 'a']++;
      if (cnt[a[i] - 'a'] >= 2) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}