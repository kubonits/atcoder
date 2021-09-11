#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int h, w, k;
int sum[12][1001];
string s[10];

int dfs(int x, vector<int> v) {
  int res = 1000000;
  if (x == h) {
    int p = 0;
    res = v.size() - 1;
    v.push_back(h);
    for (int i = 1; i <= w; i++) {
      int flag = 1;
      for (int j = 1; j < v.size(); j++) {
        if (sum[v[j]][i] - sum[v[j - 1]][i] - sum[v[j]][p] + sum[v[j - 1]][p] >
            k) {
          flag = 0;
          break;
        }
      }
      if (flag == 0 && i - 1 == p) {
        return 1000000;
      } else if (flag == 0) {
        p = i - 1;
        res++;
        int flag = 1;
        for (int j = 1; j < v.size(); j++) {
          if (sum[v[j]][i] - sum[v[j - 1]][i] - sum[v[j]][p] +
                  sum[v[j - 1]][p] >
              k) {
            flag = 0;
            break;
          }
        }
        if (flag == 0) {
          return 1000000;
        }
      }
    }
    v.pop_back();
    return res;
  }
  v.push_back(x);
  res = min(res, dfs(x + 1, v));
  v.pop_back();
  return min(res, dfs(x + 1, v));
}

int main() {
  vector<int> v;
  cin >> h >> w >> k;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      sum[i + 1][j + 1] = sum[i + 1][j];
      if (s[i][j] == '1') {
        sum[i + 1][j + 1]++;
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      sum[i + 1][j + 1] += sum[i][j + 1];
    }
  }
  v.push_back(0);
  cout << dfs(1, v);
}