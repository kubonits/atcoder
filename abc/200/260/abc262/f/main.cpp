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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int n, k, minil, minir;
  cin >> n >> k;
  minil = minir = n;
  deque<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < k; i++) {
    minil = min(minil, p[i]);
    minir = min(minir, p[n - 1 - i]);
  }
  if (minil < minir) {
    deque<int> d;
    int mini = p[0];
    d.push_back(p[0]);
    for (int i = 1; i < n; i++) {
      while (d.size() && d.back() > p[i] && k) {
        k--;
        d.pop_back();
      }
      d.push_back(p[i]);
    }
    for (int i = 0; i < d.size(); i++) {
      cout << d[i] << " ";
    }
    cout << endl;
  }
}
