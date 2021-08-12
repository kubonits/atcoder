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
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i <= 20; i++) {
    for (int j = i; j <= 20; j++) {
      if (s.find(i * i + j * j) != s.end()) {
        cout << i << " " << j << endl;
      }
      s.insert(i * i + j * j);
    }
  }
  cout << s.size() << endl;
}