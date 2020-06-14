#include <algorithm>
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

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n + 10), v2(n + 10);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      v2[j] = 0;
    }
    for (int j = 0; j < n; j++) {
      v2[max(0, j - v[j])]++;
      v2[min(n + 1, j + v[j] + 1)]--;
    }
    for (int j = 0; j < n; j++) {
      if (j) {
        v2[j] += v2[j - 1];
      }
      v[j] = v2[j];
    }
    int flag = 1;
    for (int j = 0; j < n; j++) {
      if (v[j] != n) {
        flag = 0;
      }
    }
    if (flag) {
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}