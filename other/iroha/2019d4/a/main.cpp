#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int a, b, c, d, w[100], x[100], y[100], z[100], n;
bool memo[101][101][101][101];
vector<int> ans, v = {1, 2, 3};
bool dfs(int A, int B, int C, int D) {
  if (A == a && B == b && C == c && D == d) {
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
      cout << ans[i] << endl;
    }
    return true;
  }
  if (memo[A][B][C][D] == true) {
    return false;
  }
  if (A < a && B < b && C < c) {
    vector<int> temp = {w[A], x[B], y[C]};
    sort(temp.begin(), temp.end());
    ans.push_back(4);
    if (v == temp && dfs(A + 1, B + 1, C + 1, D)) {
      return true;
    }
    ans.pop_back();
  }
  if (A < a && B < b && D < d) {
    vector<int> temp = {w[A], x[B], z[D]};
    sort(temp.begin(), temp.end());
    ans.push_back(3);
    if (v == temp && dfs(A + 1, B + 1, C, D + 1)) {
      return true;
    }
    ans.pop_back();
  }
  if (A < a && D < d && C < c) {
    vector<int> temp = {w[A], z[D], y[C]};
    sort(temp.begin(), temp.end());
    ans.push_back(2);
    if (v == temp && dfs(A + 1, B, C + 1, D + 1)) {
      return true;
    }
    ans.pop_back();
  }
  if (D < d && B < b && C < c) {
    vector<int> temp = {z[D], x[B], y[C]};
    sort(temp.begin(), temp.end());
    ans.push_back(1);
    if (v == temp && dfs(A, B + 1, C + 1, D + 1)) {
      return true;
    }
    ans.pop_back();
  }
  memo[A][B][C][D] = true;
  return false;
}

int main() {
  cin >> n >> a >> b >> c >> d;
  for (int i = 0; i < a; i++) {
    cin >> w[i];
  }
  for (int i = 0; i < b; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < c; i++) {
    cin >> y[i];
  }
  for (int i = 0; i < d; i++) {
    cin >> z[i];
  }
  if (a + b + c + d == 3 * n && dfs(0, 0, 0, 0)) {
    return 0;
  }
  cout << "No" << endl;
}