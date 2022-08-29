#include <iostream>
#include <string>
using namespace std;
int main() {
  int x, y;
  string s[9], w;
  cin >> x >> y >> w;
  for (int i = 0; i < 9; i++) {
    cin >> s[i];
  }
  x--;
  y--;
  for (int i = 0; i < 4; i++) {
    cout << s[y][x];
    if (w == "LU") {
      if (x == 0 && y == 0) {
        x++;
        y++;
        w = "RD";
      } else if (x == 0) {
        x++;
        y--;
        w = "RU";
      } else if (y == 0) {
        x--;
        y++;
        w = "LD";
      } else {
        x--;
        y--;
      }
    } else if (w == "LD") {
      if (x == 0 && y == 8) {
        x++;
        y--;
        w = "RU";
      }
      if (x == 0) {
        x++;
        y++;
        w = "RD";
      } else if (y == 8) {
        x--;
        y--;
        w = "LU";
      } else {
        x--;
        y++;
      }
    } else if (w == "RU") {
      if (x == 8 && y == 0) {
        x--;
        y++;
        w = "LD";
      } else if (x == 8) {
        x--;
        y--;
        w = "LU";
      } else if (y == 0) {
        x++;
        y++;
        w = "RD";
      } else {
        x++;
        y--;
      }
    } else if (w == "RD") {
      if (x == 8 && y == 8) {
        x--;
        y--;
        w = "LU";
      } else if (x == 8) {
        x--;
        y++;
        w = "LD";
      } else if (y == 8) {
        x++;
        y--;
        w = "RU";
      } else {
        x++;
        y++;
      }
    } else if (w == "R") {
      if (x == 8) {
        x--;
        w = "L";
      } else {
        x++;
      }
    } else if (w == "L") {
      if (x == 0) {
        x++;
        w = "R";
      } else {
        x--;
      }
    } else if (w == "U") {
      if (y == 0) {
        y++;
        w = "D";
      } else {
        y--;
      }
    } else if (w == "D") {
      if (y == 8) {
        y--;
        w = "U";
      } else {
        y++;
      }
    }
  }
  cout << endl;
}