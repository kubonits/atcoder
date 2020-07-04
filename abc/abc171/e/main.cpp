#include <algorithm>
#include <cmath>
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
  int n, sum = 0;
  cin >> n;
  vector<int> v(n + 10);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum ^= v[i];
  }
  for (int i = 0; i < n; i++) {
    cout << (sum ^ v[i]) << " ";
  }
  cout << endl;
}