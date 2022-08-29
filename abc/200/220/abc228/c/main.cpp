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
  int n, k, p, a;
  cin >> n >> k;
  vector<int> sum(n);
  priority_queue<int> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> p;
      sum[i] += p;
    }
    q.push(sum[i]);
  }
  while (k--) {
    a = q.top();
    q.pop();
  }
  for (int i = 0; i < n; i++) {
    if (sum[i] + 300 >= a) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
