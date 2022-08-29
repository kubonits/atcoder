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

int h, w;
vector<vector<int> > a(50, vector<int>(50)), sum(51, vector<int>(51)), vh, vw;

int calc(vector<int>& v, vector<int>& u) {
  for (int i = 1; i < v.size(); i++) {
    for (int j = 1; j < u.size(); j++) {
      if (sum[v[i]][u[j]] - sum[v[i - 1]][u[j]] - sum[v[i]][u[j - 1]] +
              sum[v[i - 1]][u[j - 1]] !=
          sum[v[1]][u[1]]) {
        return 0;
      }
    }
  }
  return 1;
}
int main() {
  int ans = 0;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      sum[i + 1][j + 1] = sum[i + 1][j] + a[i][j];
    }
    for (int j = 0; j < w; j++) {
      sum[i + 1][j + 1] += sum[i][j + 1];
    }
  }
  for (int i = 0; i < h; i++) {
    int p = i + 1, flag = 1;
    vector<int> v;
    v.push_back(0);
    v.push_back(i + 1);
    int x = sum[i + 1][w];
    for (int j = i + 1; j < h; j++) {
      if (sum[j + 1][w] - sum[p][w] == x) {
        p = j + 1;
        v.push_back(p);
      } else if (sum[j + 1][w] - sum[p][w] > x) {
        flag = 0;
      }
    }
    if (p == h && flag) {
      vh.push_back(v);
    }
  }
  for (int i = 0; i < w; i++) {
    int p = i + 1, flag = 1;
    vector<int> v;
    v.push_back(0);
    v.push_back(i + 1);
    int x = sum[h][i + 1];
    for (int j = i + 1; j < w; j++) {
      if (sum[h][j + 1] - sum[h][p] == x) {
        p = j + 1;
        v.push_back(p);
      } else if (sum[h][j + 1] - sum[h][p] > x) {
        flag = 0;
      }
    }
    if (p == w && flag) {
      for (int j = 0; j < vh.size(); j++) {
        ans += calc(vh[j], v);
      }
    }
  }
  cout << ans - 1 << endl;
}
