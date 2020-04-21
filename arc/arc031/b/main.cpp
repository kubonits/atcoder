#include <iostream>
#include <string>
using namespace std;

int visited[100][100];
string s[10];

void dfs(int x, int y) {
  visited[x][y] = 1;
  if (x != 0 && s[x - 1][y] == 'o' && visited[x - 1][y] == 0) {
    dfs(x - 1, y);
  }
  if (x != 9 && s[x + 1][y] == 'o' && visited[x + 1][y] == 0) {
    dfs(x + 1, y);
  }
  if (y != 0 && s[x][y - 1] == 'o' && visited[x][y - 1] == 0) {
    dfs(x, y - 1);
  }
  if (y != 9 && s[x][y + 1] == 'o' && visited[x][y + 1] == 0) {
    dfs(x, y + 1);
  }
}

int main() {
  for (int i = 0; i < 10; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        for (int l = 0; l < 10; l++) {
          visited[k][l] = 0;
        }
      }
      dfs(i, j);
      int flag = 1;
      for (int k = 0; k < 10; k++) {
        for (int l = 0; l < 10; l++) {
          if (s[k][l] == 'o' && visited[k][l] == 0) {
            flag = 0;
          }
        }
      }
      if (flag) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}