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
  int n, sum = 0;
  cin >> n;
  vector<int> v(n);
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    s.insert(v[i]);
    sum ^= v[i];
  }
  cout << (s.find(sum) != s.end() || n % 2 ? "Win" : "Lose") << endl;
}
