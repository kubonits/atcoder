#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define MAX_V 100001
#define INF 1000000000000000000
typedef long long ll;
struct edge {
  int from, to;
  ll cost;
};
using namespace std;

int visit[MAX_V];

set<int> se;

edge es[5001];

ll d[2501];

int V, E;
bool shortest_path(int s) {
  for (int i = 0; i <= V; i++) {
    d[i] = INF;
  }
  d[s] = 0;
  ll res;
  for (int j = 0; j < 2 * V; j++) {
    bool update = false;
    if (j == V) res = d[V];
    for (int i = 0; i < E; i++) {
      edge e = es[i];
      if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        update = true;
      }
    }
    if (!update) {
      return false;
    }
  }
  if (res == d[V]) {
    return false;
  } else {
    return true;
  }
}

int main() {
  ll p;
  scanf("%d %d %lld", &V, &E, &p);
  for (int i = 0; i < E; i++) {
    scanf("%d %d %lld", &es[i].from, &es[i].to, &es[i].cost);
    es[i].cost -= p;
    es[i].cost *= -1;
  }
  if (shortest_path(1)) {
    printf("-1\n");
  } else {
    printf("%lld\n", max(0LL, -d[V]));
  }
}