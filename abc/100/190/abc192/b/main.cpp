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
  string n;
  cin >> n;
  for (int i = 0; i < n.length(); i++) {
    if (i % 2 && (n[i] < 'A' || n[i] > 'Z') ||
        i % 2 == 0 && (n[i] < 'a' || n[i] > 'z')) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
