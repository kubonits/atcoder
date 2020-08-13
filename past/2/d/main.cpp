#include <algorithm>
#include <cmath>
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

int main() {
  string s, t;
  set<string> se;
  cin >> s;
  if (s.size() == 1) {
    cout << 2 << endl;
    return 0;
  }
  for (int i = 0; i < s.length(); i++) {
    se.insert(s.substr(i, 1));
  }
  se.insert(".");
  for (int i = 0; i < s.length() - 1; i++) {
    for (int j = 0; j < 4; j++) {
      t = "";
      if (j & 2) {
        t += s.substr(i, 1);
      } else {
        t += ".";
      }
      if (j & 1) {
        t += s.substr(i + 1, 1);
      } else {
        t += ".";
      }
      se.insert(t);
    }
  }
  for (int i = 0; i < s.length() - 2; i++) {
    for (int j = 0; j < 8; j++) {
      t = "";
      if (j & 4) {
        t += s.substr(i, 1);
      } else {
        t += ".";
      }
      if (j & 2) {
        t += s.substr(i + 1, 1);
      } else {
        t += ".";
      }
      if (j & 1) {
        t += s.substr(i + 2, 1);
      } else {
        t += ".";
      }
      se.insert(t);
    }
  }
  cout << se.size() << endl;
}