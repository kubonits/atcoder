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
  int n, a[100] = {}, b;
  cin >> n;
  cin >> b;
  a[b - 1] = 100000;
  cin >> b;
  a[b - 1] = 50000;
  cin >> b;
  a[b - 1] = 30000;
  cin >> b;
  a[b - 1] = 20000;
  cin >> b;
  a[b - 1] = 10000;
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
}