#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int h, w, B[101][101], W[101][101], c[100][100], ans = 0;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> c[i][j];
    }
  }
  for (int i = 0; i < h; i++) {
    B[i][0] = W[i][0] = 0;
  }
  for (int i = 0; i < w; i++) {
    B[0][i] = W[0][i] = 0;
  }
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      B[i][j] = B[i][j - 1];
      W[i][j] = W[i][j - 1];
      if ((i + j) % 2) {
        B[i][j] += c[i - 1][j - 1];
      } else {
        W[i][j] += c[i - 1][j - 1];
      }
    }
    for (int j = 1; j <= w; j++) {
      B[i][j] += B[i - 1][j];
      W[i][j] += W[i - 1][j];
    }
  }
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      for (int k = i; k <= h; k++) {
        for (int l = j; l <= w; l++) {
          int x = B[k][l] - B[i - 1][l] - B[k][j - 1] + B[i - 1][j - 1];
          int y = W[k][l] - W[i - 1][l] - W[k][j - 1] + W[i - 1][j - 1];
          if (x == y) {
            ans = max(ans, (k - i + 1) * (l - j + 1));
          }
        }
      }
    }
  }
  cout << ans << endl;
}