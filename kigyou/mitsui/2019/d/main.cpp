#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
  int n;
  string s;
  set<string> se1, se2, se3;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    for (set<string>::iterator it = se2.begin(); it != se2.end(); it++) {
      se3.insert(*it + s.substr(i, 1));
    }
    for (set<string>::iterator it = se1.begin(); it != se1.end(); it++) {
      se2.insert(*it + s.substr(i, 1));
    }
    se1.insert(s.substr(i, 1));
  }
  cout << se3.size() << endl;
}