#include <iostream>
#include <string>
using namespace std;

int r, c;
string s[20];
int visited[20][20][4][16];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int dfs(int x, int y, int d, int num) {
  if (visited[x][y][d][num] == 1) {
    return 0;
  }
  visited[x][y][d][num] = 1;
  if (s[x][y] == '<') {
    d = 1;
    return dfs((r + x + dx[d]) % r, (c + y + dy[d]) % c, d, num);
  }
  if (s[x][y] == '>') {
    d = 0;
    return dfs((r + x + dx[d]) % r, (c + y + dy[d]) % c, d, num);
  }
  if (s[x][y] == '^') {
    d = 3;
    return dfs((r + x + dx[d]) % r, (c + y + dy[d]) % c, d, num);
  }
  if (s[x][y] == 'v') {
    d = 2;
    return dfs((r + x + dx[d]) % r, (c + y + dy[d]) % c, d, num);
  }
  if (s[x][y] == '_' && num == 0) {
    d = 0;
    return dfs((r + x + dx[d]) % r, (c + y + dy[d]) % c, d, num);
  } else if (s[x][y] == '_') {
    d = 1;
    return dfs((r + x + dx[d]) % r, (c + y + dy[d]) % c, d, num);
  }
  if (s[x][y] == '|' && num == 0) {
    d = 2;
    return dfs((r + x + dx[d]) % r, (c + y + dy[d]) % c, d, num);
  } else if (s[x][y] == '|') {
    d = 3;
    return dfs((r + x + dx[d]) % r, (c + y + dy[d]) % c, d, num);
  }
  if (s[x][y] == '?') {
    int res = 0;
    for (int i = 0; i < 4; i++) {
      d = i;
      res |= dfs((r + x + dx[d]) % r, (c + y + dy[d]) % c, d, num);
    }
    return res;
  }
  if (s[x][y] == '.') {
    return dfs((r + x + dx[d]) % r, (c + y + dy[d]) % c, d, num);
  }
  if (s[x][y] == '@') {
    return 1;
  }
  if (s[x][y] >= '0' && s[x][y] <= '9') {
    num = s[x][y] - '0';
    return dfs((r + x + dx[d]) % r, (c + y + dy[d]) % c, d, num);
  }
  if (s[x][y] == '+') {
    num++;
    num %= 16;
    return dfs((r + x + dx[d]) % r, (c + y + dy[d]) % c, d, num);
  }
  if (s[x][y] == '-') {
    num += 15;
    num %= 16;
    return dfs((r + x + dx[d]) % r, (c + y + dy[d]) % c, d, num);
  }
}

int main() {
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    cin >> s[i];
  }
  if (dfs(0, 0, 0, 0)) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}