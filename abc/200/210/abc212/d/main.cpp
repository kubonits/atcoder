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
  int n, p;
  ll x, sum = 0LL;
  priority_queue<ll, vector<ll>, greater<ll> > q;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p;
    if (p == 1) {
      cin >> x;
      q.push(x - sum);
    } else if (p == 2) {
      cin >> x;
      sum += x;
    } else {
      cout << q.top() + sum << endl;
      q.pop();
    }
  }
}