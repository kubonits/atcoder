#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
int main() {
  string t;
  cin >> t;
  for (int i = 0; i < t.length(); i++) {
    if (t[i] == '?') {
      t[i] = 'D';
    }
  }
  cout << t << endl;
}