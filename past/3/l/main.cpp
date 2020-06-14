#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
vector<int> v[100000];
int p1[100000], p2[100000];
pair<int, int> head[100000];
int main() {
  int n, k, m, a;
  priority_queue<pair<int, pair<int, int> > > q1, q2;
  set<pair<int, int> > s, s1, s2;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    for (int j = 0; j < k; j++) {
      cin >> a;
      v[i].push_back(a);
    }
    v[i].push_back(0);
    v[i].push_back(0);
    q1.push({v[i][0], {i, 0}});
    p1[i] = 1;
    s1.insert({i, 0});
    q2.push({v[i][0], {i, 0}});
    p2[i] = 1;
    s2.insert({i, 1});
    head[i] = {0, 1};
    q2.push({v[i][1], {i, 1}});
    p2[i] = 2;
    s2.insert({i, 1});
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> a;
    pair<int, int> p;
    if (a == 1) {
      while (!q1.empty()) {
        p = q1.top().second;
        if (s.find(p) == s.end()) {
          break;
        }
        q1.pop();
        p = q1.top().second;
      }
      cout << q1.top().first << endl;
      s.insert(q1.top().second);
      p = q1.top().second;
      q1.pop();
      q1.push(
          {v[p.first][head[p.first].second], {p.first, head[p.first].second}});
      head[p.first].first = head[p.first].second;
      head[p.first].second++;
      q2.push(
          {v[p.first][head[p.first].second], {p.first, head[p.first].second}});
    } else {
      while (1) {
        p = q2.top().second;
        if (s.find(p) == s.end()) {
          break;
        }
        q2.pop();
        p = q2.top().second;
      }
      cout << q2.top().first << endl;
      s.insert(q2.top().second);
      p = q2.top().second;
      int x = p.first, y = p.second;
      q2.pop();
      if (y == head[x].second) {
        q2.push({v[x][y + 1], {x, y + 1}});
        head[x].second++;
      } else {
        q1.push({v[x][head[x].second], {x, head[x].second}});
        head[x].first = head[x].second;
        head[x].second++;
        q2.push({v[x][head[x].second], {x, head[x].second}});
      }
    }
  }
}