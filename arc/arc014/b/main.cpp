#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
  int n;
  string s[100];
  set<string> se;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    if (i > 0 && (s[i][0] != s[i - 1].back() || se.find(s[i]) != se.end())) {
      if (i % 2) {
        cout << "WIN" << endl;
        return 0;
      } else {
        cout << "LOSE" << endl;
        return 0;
      }
    }
    se.insert(s[i]);
  }
  cout << "DRAW" << endl;
}