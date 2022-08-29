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
  int n, a, b, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    ans += a * b;
  }
  cout << (ans + ans / 20) << endl;
}