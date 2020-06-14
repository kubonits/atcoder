#include <iostream>
#include <string>

using namespace std;

int h, w;
string s[1000];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dfs(int x, int y) {
  int res = 1;
  s[x][y] = '.';
  for (int i = 0; i < 8; i++) {
    if (x + dx[i] >= 0 && x + dx[i] < h && y + dy[i] < w && y + dy[i] >= 0 &&
        s[x + dx[i]][y + dy[i]] == 'o') {
      res += dfs(x + dx[i], y + dy[i]);
    }
  }
  return res;
}

int check(int x) {
  for (int i = 1; i <= 1000; i++) {
    if (i * i == x) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int a, b, c;
  a = b = c = 0;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == 'o') {
        int x = dfs(i, j);
        if (x % 12 == 0 && check(x / 12)) {
          a++;
        } else if (x % 16 == 0 && check(x / 16)) {
          b++;
        } else {
          c++;
        }
      }
    }
  }
  cout << a << " " << b << " " << c << endl;
}