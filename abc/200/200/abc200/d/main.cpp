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

vector<vector<int> > v(200);
int n;
vector<int> a;

int dfs(int x, int num, vector<int> b) {
  if (x == n) {
    if (!v[num].empty()) {
      cout << "Yes" << endl;
      cout << v[num].size();
      for (int i = 0; i < v[num].size(); i++) {
        cout << " " << v[num][i];
      }
      cout << endl;
      cout << b.size();
      for (int i = 0; i < b.size(); i++) {
        cout << " " << b[i];
      }
      cout << endl;
      return 1;
    }
    v[num] = b;
    return 0;
  }
  if (dfs(x + 1, num, b)) {
    return 1;
  }
  b.push_back(x + 1);
  if (dfs(x + 1, (num + a[x]) % 200, b)) {
    return 1;
  }
  return 0;
}

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b;
  if (!dfs(0, 0, b)) {
    cout << "No" << endl;
  }
}
