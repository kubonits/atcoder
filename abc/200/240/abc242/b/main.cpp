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

int main() {
  string n;
  vector<int> a(26);
  cin >> n;
  for (int i = 0; i < n.length(); i++) {
    a[n[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < a[i]; j++) {
      cout << char('a' + i);
    }
  }
  cout << endl;
}
