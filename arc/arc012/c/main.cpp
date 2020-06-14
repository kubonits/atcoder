#include <iostream>
#include <string>
using namespace std;

string s[19];
int flag;

void check() {
  int cnt;
  for (int i = 0; i < 19; i++) {
    for (int j = 0; j < 19; j++) {
      if (s[i][j] != '.') {
        cnt = 0;
        for (int k = 0; k < 5 && i + k < 19; k++) {
          if (s[i][j] == s[i + k][j]) {
            cnt++;
          }
        }
        if (cnt >= 5) {
          return;
        }
        cnt = 0;
        for (int k = 0; k < 5 && j + k < 19; k++) {
          if (s[i][j] == s[i][j + k]) {
            cnt++;
          }
        }
        if (cnt >= 5) {
          return;
        }
        cnt = 0;
        for (int k = 0; k < 5 && j + k < 19 && i + k < 19; k++) {
          if (s[i][j] == s[i + k][j + k]) {
            cnt++;
          }
        }
        if (cnt >= 5) {
          return;
        }
        cnt = 0;
        for (int k = 0; k < 5 && i - k >= 0 && j + k < 19; k++) {
          if (s[i][j] == s[i - k][j + k]) {
            cnt++;
          }
        }
        if (cnt >= 5) {
          return;
        }
      }
    }
  }
  flag = 1;
}

int main() {
  int x, y;
  x = 0;
  y = 0;
  for (int i = 0; i < 19; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < 19; i++) {
    for (int j = 0; j < 19; j++) {
      if (s[i][j] == 'o') {
        x++;
      } else if (s[i][j] == 'x') {
        y++;
      }
    }
  }
  if (x != y && x != y + 1) {
    cout << "NO" << endl;
    return 0;
  }
  flag = 0;
  check();
  for (int i = 0; i < 19; i++) {
    for (int j = 0; j < 19; j++) {
      if (x == y + 1 && s[i][j] == 'o') {
        s[i][j] = '.';
        check();
        s[i][j] = 'o';
      } else if (x == y && s[i][j] == 'x') {
        s[i][j] = '.';
        check();
        s[i][j] = 'x';
      }
    }
  }
  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}