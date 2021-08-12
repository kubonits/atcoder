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
  int h, w, a;
  cin >> h >> w;
  vector<vector<int> > v(h);
  vector<int> csum(w), rsum(h);
  for (int i = 0; i < h; i++) {
    rsum[i] = 0;
  }
  for (int i = 0; i < w; i++) {
    csum[i] = 0;
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a;
      v[i].push_back(a);
      rsum[i] += a;
      csum[j] += a;
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << rsum[i] + csum[j] - v[i][j] << " ";
    }
    cout << endl;
  }
}