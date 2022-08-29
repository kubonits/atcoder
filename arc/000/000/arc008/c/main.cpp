#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define MAX_V 100001
#define INF 1000000000000000
using namespace std;
struct edge {
  int to;
  long cost;
};
typedef pair<double, int> P;

int V;
vector<edge> G[MAX_V];
double d[MAX_V];
struct member {
  double x, y, t, r;
};
member a[1000];

double dis(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d + V, INF);
  d[s] = 0;
  que.push(P(0.0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i = 0; i < V; i++) {
      if (d[i] >
          d[v] + dis(a[v].x, a[v].y, a[i].x, a[i].y) / min(a[v].t, a[i].r)) {
        d[i] = d[v] + dis(a[v].x, a[v].y, a[i].x, a[i].y) / min(a[v].t, a[i].r);
        que.push(P(d[i], i));
      }
    }
  }
}

int main() {
  double ans = 0.0;
  cin >> V;
  for (int i = 0; i < V; i++) {
    cin >> a[i].x >> a[i].y >> a[i].t >> a[i].r;
  }
  dijkstra(0);
  sort(d, d + V);
  for (int i = 1; i < V; i++) {
    ans = max(ans, d[i] + (double)(V - i - 1));
  }
  cout << fixed << setprecision(7) << ans << endl;
}