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
  int n, a[30] = {}, b;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b;
    a[b]++;
  }
  for (int i = 0; i < 30; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}