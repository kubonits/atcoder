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

struct node {
  int end, depth;
  node *child[26];
  node(int d) {
    end = 0;
    depth = d;
    for (int i = 0; i < 26; i++) {
      child[i] = NULL;
    }
  }
  void insert(int key) {
    node *x = new node(depth + 1);
    child[key] = x;
  }
};

int main() {
  int n;
  ll ans = 0LL;
  node head = node(0);
  head.depth = 0;
  string s;
  vector<pair<int, string> > v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    reverse(s.begin(), s.end());
    v.push_back({s.length(), s});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    node *x = &head;
    vector<int> f[26];
    for (int j = 0; j < 26; j++) {
      f[j].resize(v[i].first);
      for (int k = v[i].first - 1; k >= 0; k--) {
        if (v[i].second[k] == 'a' + j || k != v[i].first - 1 && f[j][k + 1]) {
          f[j][k] = 1;
        }
      }
    }
    for (int j = 0; j < v[i].first; j++) {
      int flag = 0;
      if (x->end == 1) {
        ans++;
      }
      for (int k = 0; k < 26; k++) {
        if (x->child[k] != NULL && v[i].second[j] == 'a' + k) {
          flag = 1;
        } else if (x->child[k] != NULL && x->child[k]->end == 1 && f[k][j]) {
          ans++;
        }
      }
      if (flag) {
        x = x->child[v[i].second[j] - 'a'];
      } else {
        x->insert(v[i].second[j] - 'a');
        x = x->child[v[i].second[j] - 'a'];
      }
      if (j == v[i].first - 1) {
        x->end = 1;
      }
    }
  }
  cout << ans << endl;
}