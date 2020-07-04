#include <iostream>
#include <string>
using namespace std;

int visited[101][100001];
string s[100], t[100];

int main() {
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
    t[i] = "";
    for (int j = 0; j < 1000; j++) {
      t[i] += s[i];
    }
  }
  visited[0][0] = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < 1000 * w; j++) {
      if (visited[i][j]) {
        if (t[i + 1][j % w] == '.') {
          visited[i + 1][j] = 1;
        }
        if (t[i][(j + 1) % w] == '.') {
          visited[i][(j + 1)] = 1;
        }
      }
    }
  }
  cout << (visited[h - 1][1000 * w - 1] ? "Yay!" : ":(") << endl;
}