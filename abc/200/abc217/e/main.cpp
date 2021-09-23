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

int main() {
  int n, c, x;
  queue<int> q;
  priority_queue<int, vector<int>, greater<int> > pq;
  cin >> n;
  while (n--) {
    cin >> c;
    if (c == 1) {
      cin >> x;
      q.push(x);
    } else if (c == 2) {
      if (!pq.empty()) {
        x = pq.top();
        pq.pop();
        cout << x << endl;
      } else {
        x = q.front();
        q.pop();
        cout << x << endl;
      }
    } else {
      while (!q.empty()) {
        pq.push(q.front());
        q.pop();
      }
    }
  }
}