#include <iostream>
using namespace std;
int main() {
  int a, b, c[10] = {}, p;
  cin >> a >> b;
  for (int i = 0; i < a; i++) {
    cin >> p;
    c[p] = 1;
  }
  for (int i = 0; i < b; i++) {
    cin >> p;
    c[p] = 2;
  }
  for (int i = 7; i <= 10; i++) {
    if (c[i % 10] == 1) {
      cout << ". ";
    } else if (c[i % 10] == 2) {
      cout << "o ";
    } else {
      cout << "x ";
    }
  }
  cout << endl;
  cout << " ";
  for (int i = 4; i <= 6; i++) {
    if (c[i % 10] == 1) {
      cout << ". ";
    } else if (c[i % 10] == 2) {
      cout << "o ";
    } else {
      cout << "x ";
    }
  }
  cout << endl;
  cout << "  ";
  for (int i = 2; i <= 3; i++) {
    if (c[i % 10] == 1) {
      cout << ". ";
    } else if (c[i] == 2) {
      cout << "o ";
    } else {
      cout << "x ";
    }
  }
  cout << endl;
  cout << "   ";
  for (int i = 1; i <= 1; i++) {
    if (c[i % 10] == 1) {
      cout << ". ";
    } else if (c[i] == 2) {
      cout << "o ";
    } else {
      cout << "x ";
    }
  }
  cout << endl;
}