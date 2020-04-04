#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void dfs(int x, int y, string s) {
  if (x == y) {
    cout << s << endl;
    return;
  }
  char c = 'a';
  string st = "a";
  for (int i = 0; i < s.size(); i++) {
    c = max(c, s[i]);
  }
  for (int i = 0; i + 'a' <= c + 1; i++) {
    st[0] = 'a' + i;
    dfs(x + 1, y, s + st);
  }
}

int main() {
  int n;
  cin >> n;
  dfs(1, n, "a");
}