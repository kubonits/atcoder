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
  int n, l;
  cin >> n;
  set<vector<int> > s;
  vector<vector<int> > v(n);
  for (int i = 0; i < n; i++) {
    cin >> l;
    v[i].resize(l);
    for (int j = 0; j < l; j++) {
      cin >> v[i][j];
    }
    s.insert(v[i]);
  }
  cout << s.size() << endl;
}
