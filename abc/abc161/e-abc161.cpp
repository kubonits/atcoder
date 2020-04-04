#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
int n, k, c, a[200000];
string s;
int mini[200000], maxi[200000];
int main() {
  cin >> n >> k >> c;
  cin >> s;
  maxi[0] = -1;
  set<pair<int, int> > sl, sr;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'o') {
      a[i] = 1;
      maxi[i] = i;
    } else if (i == 0) {
      maxi[i] = -1;
    } else {
      maxi[i] = maxi[i - 1];
    }
  }
  mini[n - 1] = n;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'o') {
      mini[i] = i;
    } else if (i == n - 1) {
      mini[i] = n;
    } else {
      mini[i] = mini[i + 1];
    }
  }
  int cnt = 0;
  int p = 0;
  while (a[p] == 0) {
    p++;
  }
  cnt++;
  sl.insert({p + 1, 1});
  while (cnt < k) {
    sl.insert({mini[p + c + 1] + 1, cnt + 1});
    p = mini[p + c + 1];
    cnt++;
  }
  cnt = 1;
  p = n - 1;
  while (a[p] == 0) {
    p--;
  }
  sr.insert({p + 1, k});
  while (k - cnt) {
    p = maxi[p - c - 1];
    sr.insert({p + 1, k - cnt});
    cnt++;
  }
  decltype(sl)::iterator it = sl.begin();

  while (it != sl.end()) {
    pair<int, int> aaa = *it;
    if (sr.find(*it) != sr.end()) {
      printf("%d\n", aaa.first);
    }
    it++;
  }
  printf("\n");
}