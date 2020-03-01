#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n, w, k, v, c[1000], a[8];
  pair<int, int> p[1000];
  int score = 0;
  int r, cnt;
  int maxi;
  set<int> se[8];
  vector<int> vec[8];
  int x, y;
  srand((unsigned)time(NULL));
  scanf("%d%d%d%d", &n, &w, &k, &v);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &p[i].first, &p[i].second);
  }
  for (int i = 0; i < n; i++) {
    se[i % 8].insert(i);
  }
  set<int>::iterator it[8];
  for (int i = 0; i < 8; i++) {
    it[i] = se[i].begin();
  }
  for (int i = 0; i < 125; i++) {
    for (int j = 0; j < 6; j++) {
      a[j] = 0;
    }
    for (int j = 0; j < 8; j++) {
      a[p[*it[j]].first] += p[*it[j]].second;
      it[j]++;
    }
    maxi = 0;
    for (int j = 0; j < 6; j++) {
      maxi = max(maxi, a[j]);
    }
    cnt += maxi;
  }
  score = cnt;
  int aaa = 125000;
  int r1, r2;
  while (aaa--) {
    r1 = rand() % 1000;
    x = -1;
    y = -1;
    for (int i = 0; i < 8; i++) {
      if (se[i].find(r1) != se[i].end()) {
        x = i;
      }
    }
    do {
      r2 = rand() % 1000;
      for (int i = 0; i < 8; i++) {
        if (se[i].find(r2) != se[i].end()) {
          y = i;
        }
      }
    } while (x == y);
    if (x == -1 || y == -1) {
      printf("error\n");
    }
    se[x].erase(r1);
    se[x].insert(r2);
    se[y].erase(r2);
    se[y].insert(r1);
    cnt = 0;
    for (int i = 0; i < 8; i++) {
      it[i] = se[i].begin();
    }
    for (int i = 0; i < 125; i++) {
      for (int j = 0; j < 6; j++) {
        a[j] = 0;
      }
      for (int j = 0; j < 8; j++) {
        a[p[*it[j]].first] += p[*it[j]].second;
        it[j]++;
      }
      maxi = 0;
      for (int j = 0; j < 6; j++) {
        maxi = max(maxi, a[j]);
      }
      cnt += maxi;
    }
    if (score < cnt) {
      score = cnt;
    } else {
      se[y].erase(r1);
      se[y].insert(r2);
      se[x].erase(r2);
      se[x].insert(r1);
    }
  }
  for (int i = 0; i < 8; i++) {
    it[i] = se[i].begin();
    while (it[i] != se[i].end()) {
      c[*it[i]] = i;
      it[i]++;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d\n", c[i]);
  }
}