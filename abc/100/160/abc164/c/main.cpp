#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  set<string> a;
  for (int i = 0; i < n; i++) {
    cin >> s;
    a.insert(s);
  }
  cout << a.size() << endl;
}